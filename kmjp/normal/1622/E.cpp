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


int T,N,M;
ll X[10];
string S[101010];
int ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>X[i];
		FOR(i,N) cin>>S[i];
		ll ma=-1;
		int mask=0;
		FOR(mask,1<<N) {
			vector<pair<int,int>> cand;
			FOR(x,M) {
				int mul=0;
				FOR(y,N) if(S[y][x]=='1') {
					if(mask&(1<<y)) {
						mul--;
					}
					else {
						mul++;
					}
				}
				cand.push_back({mul,x});
			}
			ll rs=0;
			FOR(y,N) {
				if(mask&(1<<y)) {
					rs+=X[y];
				}
				else {
					rs-=X[y];
				}
			}
			sort(ALL(cand));
			FOR(x,M) {
				rs+=1LL*(x+1)*cand[x].first;
			}
			if(rs>ma) {
				ma=rs;
				FOR(x,M) ret[cand[x].second]=x+1;
			}
		}
		FOR(x,M) cout<<ret[x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}