#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,m,t;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll f[66][10050],n,res=1;

ll get(ll x,ll y){
	int i,j,k;ll res=0;
	memset(f,0,sizeof(f));
	f[y][0]=1;
	for(i=0;i<m;i++){
		for(j=0;j<=y;j++){
			for(k=0;k<=j;k++){
				f[k][i+1]=(f[k][i+1]+f[j][i]*ksm(j+1,M-2))%M;
			}
		}
	}
	for(i=0;i<=y;i++){
		//cout<<f[i][m]<<endl;
		res+=f[i][m]*ksm(x,i)%M;
	}
	return res%M;
}

int main(){
	scanf("%lld%d",&n,&m);
	for(ll i=2;i*i<=n;i++){
		if(n%i){continue;}
		k=0;
		while(!(n%i)){
			k++;n/=i;
		}
		res=res*get(i,k)%M;
	}
	if(n-1){
		res=res*get(n,1)%M;
	}
	printf("%lld",res);
}