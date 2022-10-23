#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
string S;

ll F[60];
const ll mo=998244353;

int dfs(int cur,int pos) {
	if(cur<=1) return cur;
	if(pos<=F[cur-1]) return dfs(cur-1,pos);
	return dfs(cur-2,pos-F[cur-1]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=F[1]=1;
	for(i=2;i<=55;i++) {
		F[i]=F[i-1]+F[i-2];
	}
	
	
	map<int,ll> from[55],to[55];
	int first=1;
	cin>>N;
	FOR(i,N) {
		cin>>S;
		FORR(c,S) {
			if(first) {
				first=0;
				if(c=='0') from[0][1]=1;
				else from[1][1]=1;
				continue;
			}
			c-='0';
			FOR(j,55) to[j].clear();
			FOR(j,55) FORR2(a,b,from[j]) {
				//split
				if(j==50||a<F[j]) {
					(to[c][1]+=b)%=mo;
				}
				//con
				if(j==50) {
					(to[50][1]+=b)%=mo;
				}
				else if(a==F[j]) {
					if(j==0) {
						(to[50][1]+=b)%=mo;
					}
					else if(dfs(j+1,a+1)==c) {
						(to[j+1][a+1]+=b)%=mo;
					}
					else {
						(to[50][1]+=b)%=mo;
					}
				}
				else {
					if(dfs(j,a+1)==c) {
						(to[j][a+1]+=b)%=mo;
					}
					else {
						(to[50][1]+=b)%=mo;
					}
				}
			}
			swap(from,to);
		}
		ll ret=0;
		FOR(j,55) FORR2(a,b,from[j]) if(j==50||a!=F[j]) ret+=b;
		cout<<ret%mo<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}