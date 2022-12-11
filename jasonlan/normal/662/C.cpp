#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=20,maxm=101000,mod=998244353;
int n,m;
int num[maxm];
int a[1<<maxn],b[1<<maxn],cnt[1<<maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void fwt_xor(int *f,int op){
	for(register int o=2,k=1;o<=n;o<<=1,k<<=1)
		for(register int i=0;i<n;i+=o)
			for(register int j=0,x,y;j<k;++j){
				x=f[i+j];y=f[i+j+k];
				f[i+j]=(x+y)*1ll*op%mod;
				f[i+j+k]=(x-y+mod)*1ll*op%mod;
			}
}
int main(){
	n=read();m=read();
	for(register int i=0;i<n;++i){
		string s;cin>>s;
		for(register int j=0;j<m;++j)
			num[j]=(num[j]<<1)|(s[j]-'0');
	}
	for(register int j=0;j<m;++j)
		++a[num[j]];
	for(register int i=1;i<1<<n;++i){
		cnt[i]=cnt[i^(i&-i)]+1;
		b[i]=min(cnt[i],n-cnt[i]);
	}
	n=1<<n;
	fwt_xor(a,1);fwt_xor(b,1);
	for(register int i=0,x;i<n;++i)
		a[i]=1ll*a[i]*b[i]%mod;
	fwt_xor(a,(mod+1)/2);
	int ans=maxn*maxm;
	for(register int i=0;i<n;++i)
		ans=min(ans,a[i]);
	printf("%d\n",ans);
	return 0;
}