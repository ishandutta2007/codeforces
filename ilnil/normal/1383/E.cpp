#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e6+5,mo=1e9+7;
int n,zero,ans;
int pre[N],f[N],pos[N],nx0[N],nx1[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n)if(s[i]=='1')break;else ++zero;
	if(zero==n){
		printf("%d\n",n);
		return 0;
	}
	++zero;
	fo(i,1,n)
		pre[i]=s[i]=='1'?0:pre[i-1]+1;
	fd(i,1,n){
		pos[pre[i]]=i;
		nx0[i]=pos[pre[i]+1];
		nx1[i]=s[i+1]=='1'?i+1:nx1[i+1];
	}
	f[zero]=1;
	fo(i,zero,n){
		f[nx0[i]]=(f[nx0[i]]+f[i])%mo;
		f[nx1[i]]=(f[nx1[i]]+f[i])%mo;
		if(pre[i]<=pre[n])ans=(ans+f[i])%mo;
	}
	printf("%d\n",(ll)ans*zero%mo);
}