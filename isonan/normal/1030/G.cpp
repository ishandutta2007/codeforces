#include <cstdio>
#include <algorithm>

typedef long long ll;
int mxpower[2000001],cnt[2000001],n,a[2000001],now,P=1000000007;
bool choose[2000001];
bool check(int x){
	for(int i=2;i*i<=x;i++){
		int tem=0;
		while(x%i==0)x/=i,++tem;
		if(mxpower[i]==tem&&cnt[i]==1)return 0;
	}
	if(x>1)
		if(mxpower[x]==1&&cnt[x]==1)return 0;
	return 1;
}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(int i=n;i;i--)
		if(mxpower[a[i]]){
			choose[i]=1;
			int tem=a[i]-1;
			for(int j=2;j*j<=tem;j++)
				if(tem%j==0){
					int po=0;
					while(tem%j==0)tem/=j,++po;
					if(mxpower[j]==po)++cnt[j];
					else if(mxpower[j]<po)mxpower[j]=po,cnt[j]=1;
				}
			if(tem>1)
				if(mxpower[tem]==1)++cnt[tem];
				else if(mxpower[tem]<1)mxpower[tem]=cnt[tem]=1;
		}
		else mxpower[a[i]]=cnt[a[i]]=1;
	for(int i=n;i;i--)
		if(choose[i]){
			if(check(a[i]-1)&&!now){
				now=1;
				int tem=a[i]-1;
				for(int j=2;j*j<=tem;j++)
					if(tem%j==0){
						int po=0;
						while(tem%j==0)tem/=j,++po;
						if(mxpower[j]==po)--cnt[j];
					}
				if(tem>1)
					if(mxpower[tem]==1)--cnt[tem];
			}
		}
		else{
			if(cnt[a[i]]>1)--cnt[a[i]],now=1;
		}
	int ans=1;
	for(int i=2;i<=2000000;i++)
		ans=1ll*ans*qsm(i,mxpower[i])%P;
	printf("%d",(ans+now)%P);
}