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

int T;
int N;
ll K;
ll fact[1010],cycle[1010];;
ll dp[52][52];
int tar[52],vis[52];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=1000;i++) {
		if((double)fact[i-1]*i>1e18) fact[i]=5+1e18;
		else fact[i]=fact[i-1]*i;
	}
	FOR(i,51) cycle[i]=(i-2)>=0?fact[i-2]:1;
	
	for(x=1;x<=50;x++) {
		dp[x][x+1]=1;
		for(i=x;i>=1;i--) {
			for(j=i;j<=x;j++) {
				double add=(double)dp[x][j+1]*cycle[j-i+1];
				if(add+dp[x][i]>1e18) {
					dp[x][i]=5+1e18;
				}
				else {
					dp[x][i]+=dp[x][j+1]*cycle[j-i+1];
				}
			}
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		if(dp[N][1]<K) {
			cout<<-1<<endl;
		}
		else {
			K--;
			FOR(i,N+1) tar[i]=i,vis[i]=0;
			i=1;
			vector<int> V;
			
			while(i<=N) {
				for(j=i;j<=N;j++) {
					//cout<<i<<j<<" "<<dp[N][j+1]<<" "<<dp[N][j+1]*cycle[j-i+1]<<" "<<K<<endl;
					if(dp[N][j+1]*cycle[j-i+1]<=K) {
						K-=dp[N][j+1]*cycle[j-i+1];
					}
					else {
						ll num=K/dp[N][j+1];
						K%=dp[N][j+1];
						V.push_back(j);
						swap(tar[j],tar[V.size()]);
						vis[j]=1;
						while(V.size()<j-1) {
							for(x=i;x<=j;x++) if(vis[x]==0 && tar[x]!=(int)V.size()+1) {
								ll cand=fact[max(2,j-(int)V.size())-2];
								//cout<<x<<"!"<<num<<" "<<cand<<endl;
								if(cand<=num) {
									num-=cand;
								}
								else {
									V.push_back(x);
									int a=tar[V.size()];
									int b=tar[x];
									tar[b]=a;
									tar[a]=b;
									vis[x]=1;
									break;
								}
							}
						}
						for(x=i;x<=j;x++) if(vis[x]==0) V.push_back(x);
						i=j+1;
						break;
					}
				}
			}
			FORR(v,V) cout<<v<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}