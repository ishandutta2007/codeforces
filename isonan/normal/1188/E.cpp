#include <cstdio>
#include <algorithm>

int k,a[100001],tem,invmul[2000001],_mul[2000001],cnt[100001],ans;
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int IsCritical(){
	for(int i=1;i<=k;i++)if(a[i]<i-1)return i-1;
	return 0;
}
int C(int n,int m){return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",a+i);
	std::sort(a+1,a+k+1);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=2000000;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=2000000;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=2000000;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	if(tem=IsCritical()){
		ans=1;
		for(int i=1,j=1;i<tem;i++){
			while(j<=k&&a[j]<i)++j;
			ans=add(ans,C(k+i-j,k-1));
			if(j>k)break;
		}
		printf("%d\n",ans);
	}
	else{
		long long tot=0,tem=0;
		for(int i=1;i<=k;i++)tot+=a[i],tem+=a[i]%k,++cnt[a[i]%k];
		for(int i=1;i<k;i++)cnt[i]+=cnt[i-1];
		for(int i=0;i<k;i++){
			long long t=(tot-tem+(k-cnt[k-1-i])*k-i*k)/k;
			ans=add(ans,C(k+t-1,k-1));
		}
		printf("%d\n",ans);
	}
}