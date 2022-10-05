#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M;
int L[2020],S[2020];
int C[5050];

map<int,int> dp[5050];
int best[1<<12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>L[N-1-i], L[N-1-i]--;
	FOR(i,N) cin>>S[N-1-i];
	FOR(i,N+M) cin>>C[i];
	
	int ret=0;
	FOR(i,M) {
		FOR(j,1<<12) best[j]=-1<<30;
		best[0]=0;
		
		FOR(j,N) {
			
			/*cout<<i<<j<<" ";
			FOR(k,5) cout<<k<<":"<<best[k]<<"  ";
			cout<<endl;*/
			if(L[j]==i) {
				FOR(k,1<<12) if(best[k]>-1<<30) {
					int nex=best[k]-S[j];
					int nem=k;
					FOR(x,12) {
						nex+=C[L[j]+x];
						nem^=1<<x;
						if((nem&(1<<x))) {
							if(dp[j].count(nem)==0) {
								dp[j][nem]=nex;
							}
							else {
								dp[j][nem]=max(dp[j][nem],nex);
							}
							break;
						}
					}
				}
				/*
				cout<<j<<"  ";
				FORR(m,dp[j]) cout<<m.first<<":"<<m.second<<" ";
				cout<<endl;
				*/
			}
			else if(L[j]<i) {
				map<int,int> ok;
				FORR(v,dp[j]) {
					if(ok.count(v.first/2)==0) {
						ok[v.first/2]=v.second;
					}
					else {
						ok[v.first/2]=max(ok[v.first/2],v.second);
					}
				}
				swap(dp[j],ok);
				/*
				cout<<j<<"  ";
				FORR(m,dp[j]) cout<<m.first<<":"<<m.second<<" ";
				cout<<endl;
				*/
			}
			FORR(v,dp[j]) {
				best[v.first]=max(best[v.first],v.second);
				ret=max(ret,v.second);
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}