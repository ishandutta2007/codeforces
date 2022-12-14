#include<bits/stdc++.h>
using namespace std;
#define N 15
#define inf 100000000
int dp[N+1][N][1<<N],from[N][N][1<<N],fl,T,n,st_,dd[N],val[1<<N],a[N],i,j,k,l,ST,st,f1,f2;
inline void MIN(int &x,int y){if(y<x)x=y;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=0;i<n;++i){
			cin>>a[i];
		}
		for(i=0;i<(1<<n);++i)val[i]=0;fl=0;
		for(i=0;i<n;++i)dd[i]=-1;
		for(i=0;i<(1<<n);++i)
			for(j=0;j<n;++j)
				if((i>>j)&1)val[i]+=a[j];
		for(j=0;j<n;++j)
			for(k=0;k<(1<<n);++k)
				dp[1][j][k]=((1<<j)&k)?val[k]:inf;
		for(i=2;i<=n;++i)
			for(j=0;j<n;++j)
				for(k=0;k<(1<<n);++k)
					dp[i][j][k]=inf;
		for(i=1;i<n;++i){
			for(j=i-1;j<n;++j){
				for(k=0;k<(1<<n);++k){
					if(dp[i][j][k]!=inf){
					for(l=j+1;l<n;++l){
						if(((k)&(1<<l))==0){
						ST=(k^((1<<n)-1))^(1<<l);
						st_=(1<<l)|k;
						for(st=ST;~st;st=(st-1)&ST){
							if(val[st|(1<<l)]>dp[i][j][k]){
								st_=st_^st;
								if(val[st|(1<<l)]<dp[i+1][l][st_])dp[i+1][l][st_]=val[st|(1<<l)],from[i+1][l][st_]=(j<<n)+k;
								st_=st_^st;
							}
							if(st==0)break;
						}
						}
					}
					}
				}
			}
		}
//		for(i=1;i<=n;++i){
//			for(j=0;j<n;++j){
//				for(k=0;k<(1<<n);++k){
//					cout<<i<<" "<<j+1<<" "<<k<<" "<<dp[i][j][k]<<"\n";
//				}
//			}
//		}
		for(i=n;i;--i){
			for(j=n-1;~j;--j){
				if(dp[i][j][(1<<n)-1]!=inf){
		//			cout<<i<<" "<<j<<" "<<dp[8][7][(1<<n)-1]<<"\n\n";
					cout<<n-i<<"\n";
					st=(1<<n)-1;
					for(k=i;k;--k){
						f1=from[k][j][st]/(1<<n);
						f2=from[k][j][st]%(1<<n);
						for(l=0;l<n;++l){
							if(((1<<l)&(st^f2))&&l!=j){
								cout<<l-dd[l]<<" "<<j-dd[j]<<"\n";
								for(ST=l+1;ST<=n;++ST)++dd[ST];
							}
						}
				//		cout<<f1<<" "<<f2<<"\n\n\n";
						j=f1;
						st=f2;
					}
					fl=1;
					break;
				}
			}
			if(fl)break;
		}
	}
	return 0;
}