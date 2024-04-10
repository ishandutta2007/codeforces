#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}p>>=1;a=a*a%M;}return res;}
unordered_map<int,int> mp;
int i,j,k,m,t,x,n,tmp2,tmp3,tmp4,a[200500];
ll res=1,sum,tmp,jc[200500],inv[200500];

int main(){
	jc[0]=1;
	for(i=1;i<=200000;i++){
		jc[i]=jc[i-1]*i%M;
	}
	inv[200000]=ksm(jc[200000],M-2);
	for(i=199999;i>=1;i--){
		inv[i]=inv[i+1]*(i+1)%M;
	}
	inv[0]=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		mp[a[i]]++;
	}
	if(sum%n){puts("0");return 0;}
	tmp=sum/n;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		if(a[i]<tmp){tmp2++;}
		if(a[i]>tmp){tmp3++;}
	}
	if(!tmp2&&!tmp3){puts("1");return 0;}
	tmp4=n-tmp2-tmp3;
	
	if(tmp2==1||tmp3==1){
		res=jc[n];
		for(i=1;i<=n;i++){
			res=res*inv[mp[a[i]]]%M;
			mp[a[i]]=0;
		}
		printf("%lld",res);return 0;
	}
	
	res=res*jc[n]%M*inv[tmp4]%M*inv[n-tmp4]%M*2%M;
	res=res*jc[tmp2]%M*jc[tmp3]%M;
	mp[tmp]=0;
	for(i=1;i<=n;i++){
		res=res*inv[mp[a[i]]]%M;
		mp[a[i]]=0;
	}
	printf("%lld",res);
}