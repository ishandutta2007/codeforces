#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;

int i,j,k,n,m,a[100500];
ll f[1005],tmp,res,tmp2;
vector<int>v[100500];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);a[k+1]++;
	}
	k=n;
	for(i=1;i<=100000;i++){
		for(j=i;j<=100000;j+=i){
			v[j].push_back(i);
		}
		k-=a[i];a[i]=k;
	}
	for(i=1;i<=100000;i++){
		tmp=1;
		m=v[i].size();
		f[m+1]=tmp2=0;
		for(j=m;j>=1;j--){
			k=v[i][j-1];
			f[j]=a[k]-tmp2;tmp2+=f[j];
			tmp=tmp*ksm(j,f[j])%M;
		}
		if(!f[m]){continue;}
		tmp=tmp*ksm(ksm(m,f[m]),M-2)%M*(ksm(m,f[m])+M-ksm(m-1,f[m]))%M;
		res+=tmp;
	}
	printf("%lld",res%M);
}