#include<bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
#define mod 998244353
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int T,n,i,a[N],fl,k,j,col,f1,f2,f3,c1,e[N][N];
int main(){
	cin>>n;
	cin>>c1;f1=c1;f2=c1%3+1;f3=f2%3+1;
	cout<<f2<<" "<<1<<' '<<1<<"\n";fflush(stdout);
	e[1][1]=f2;
	for(i=2;i<=n*n;++i){
		cin>>col;
		if(col==f1){
			fl=0;
			for(j=1;j<=n;++j){
				for(k=1;k<=n;++k){
					if(!((j+k)&1)){
						if(!e[j][k]){
							e[j][k]=1;
							cout<<f2<<" "<<j<<" "<<k<<"\n";fl=1;break;
						}
					}
				}
				if(fl)break;
			}
			if(!fl){
				for(j=1;j<=n;++j){
					for(k=1;k<=n;++k){
						if(!e[j][k]){
							e[j][k]=1;
							cout<<f3<<" "<<j<<' '<<k<<"\n";fl=1;break;
						}
					}
					if(fl)break;
				}
			}
		}
		if(col==f2){
			fl=0;
			for(j=1;j<=n;++j){
				for(k=1;k<=n;++k){
					if(((j+k)&1)){
						if(!e[j][k]){
							e[j][k]=1;
							cout<<f1<<" "<<j<<" "<<k<<"\n";fl=1;break;
						}
					}
				}
				if(fl)break;
			}
			if(!fl){
				for(j=1;j<=n;++j){
					for(k=1;k<=n;++k){
						if(!e[j][k]){
							e[j][k]=1;
							cout<<f3<<" "<<j<<' '<<k<<"\n";fl=1;break;
						}
					}
					if(fl)break;
				}
			}
		}
		if(col==f3){
			fl=0;
			for(j=1;j<=n;++j){
				for(k=1;k<=n;++k){
					if(!e[j][k]){
						e[j][k]=1;
						if((j+k)&1)cout<<f1<<' '<<j<<" "<<k<<"\n";
						else cout<<f2<<" "<<j<<" "<<k<<"\n";
						fl=1;break;
					}
				}
				if(fl)break;
			}
		}
		fflush(stdout);
	}
	return 0;
}