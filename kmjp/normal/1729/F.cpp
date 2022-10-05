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

int T;
int N;
string S;
int W,M;
int sum[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,N) {
			sum[i+1]=sum[i]+S[i]-'0';
		}
		cin>>W>>M;
		vector<int> V[9];
		for(i=0;i+W<=N;i++) {
			x=(sum[i+W]-sum[i])%9;
			V[x].push_back(i);
		}
		while(M--) {
			int L=1000000,R=-1;
			int X,Y,K;
			cin>>X>>Y>>K;
			int v=(sum[Y]-sum[X-1])%9;
			FOR(x,9) if(V[x].size()) FOR(y,9) if(V[y].size()) {
				if((x*v+y)%9==K) {
					int a=V[x][0];
					int b=V[y][0];
					if(a==b) {
						if(V[y].size()==1) continue;
						b=V[y][1];
					}
					if(a<L) L=a,R=b;
					if(a==L&&b<R) L=a,R=b;
				}
			}
			if(R==-1) {
				cout<<"-1 -1"<<endl;
			}
			else {
				cout<<(L+1)<<" "<<(R+1)<<endl;
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}