#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int i,j,k,n,m,t;
ll p,a[1005000],sb1,sb2;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&p);
		sb1=sb2=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(p==1){
			printf("%d\n",n&1);continue;
		}
		sort(a+1,a+n+1);
		for(i=n;i>=1;i--){
			aaa:;
			if(sb2==-1){
				sb1=(sb1+M-ksm(p,a[i]))%M;continue;
			}
			if(!sb2){sb1=a[i];sb2=1;continue;}
			while(sb1>a[i]){
				sb1--;
				sb2*=p;
				if(sb2>=2000000){sb2%=M;sb1=ksm(p,sb1)*sb2%M;sb2=-1;goto aaa;}
			}
			sb2--;
		}
		if(sb2!=-1){sb1=ksm(p,sb1)*sb2%M;}
		printf("%lld\n",sb1);
	}
}