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

int dp[2020][10][10][10][10];
int N;
int A[2020],B[2020];
int T[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	FOR(i,N+1) FOR(x,10) FOR(y,10) FOR(j,10) FOR(k,10) dp[i][x][y][j][k]=1<<30;
	
	dp[0][0][0][0][B[0]]=A[0]-1;
	for(i=1;i<N;i++) {
		for(T[0]=0;T[0]<=9;T[0]++) {
			for(T[1]=T[0];T[1]<=9;T[1]++) {
				for(T[2]=T[1];T[2]<=9;T[2]++) {
					for(T[3]=T[2];T[3]<=9;T[3]++) if(dp[i-1][T[0]][T[1]][T[2]][T[3]]<1<<30) {
						int from=A[i-1];
						int to=A[i];
						vector<int> L,H,C1,C2;
						L.push_back(min(from,to));
						FOR(j,4) if(T[j] && T[j]<min(from,to)) L.push_back(T[j]);
						H.push_back(max(from,to));
						FOR(j,4) if(T[j] && T[j]>max(from,to)) H.push_back(T[j]);
						
						FORR(lo,L) FORR(hi,H) {
							int dist=abs(from-to)+2*(min(from,to)-lo)+2*(hi-max(from,to));
							vector<int> lef;
							lef.push_back(B[i]);
							FOR(j,4) if(T[j] && T[j]<lo || T[j]>hi) lef.push_back(T[j]);
							if(lef.size()>4) continue;
							while(lef.size()<4) lef.push_back(0);
							sort(ALL(lef));
							dp[i][lef[0]][lef[1]][lef[2]][lef[3]]=min(dp[i][lef[0]][lef[1]][lef[2]][lef[3]],dp[i-1][T[0]][T[1]][T[2]][T[3]]+dist);
						}
					}
				}
			}
		}
	}
	
	int ret=1<<30;
	for(T[0]=0;T[0]<=9;T[0]++) {
		for(T[1]=T[0];T[1]<=9;T[1]++) {
			for(T[2]=T[1];T[2]<=9;T[2]++) {
				for(T[3]=T[2];T[3]<=9;T[3]++) if(dp[N-1][T[0]][T[1]][T[2]][T[3]]<1<<30) {
					int lo=A[N-1],hi=A[N-1];
					FOR(i,4) if(T[i]) lo=min(lo,T[i]),hi=max(hi,T[i]);
					ret=min(ret,dp[N-1][T[0]][T[1]][T[2]][T[3]]+(hi-lo)+min(A[N-1]-lo,hi-A[N-1]));
				}
			}
		}
	}
	cout<<ret+(2*N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}