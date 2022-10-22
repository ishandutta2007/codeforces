#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e6+9;
char b0[109],t[M],c[M],s[M],d[M];
int n,q,k,m,num,Ans;
int pw[M],sum[M][29];
bool pd(int l){
	num=0;
	int len=strlen(s+1);
	int r=l;
	while(r<=len){
		for(int i=r;i<r+m;++i){
			if(i>=1&&i<=len&&b0[i-r+1]!=s[i])return 0;
		}
		r+=m+1;
		if(r-1<=len)c[++num]=s[r-1];
	}
	if(num==0)Ans=(1ll*Ans+1ll*pw[k])%mod;
	return 1;
}
int solve(char *b,int len,int x){
	if(x==k&&len>1)return 0;
	if(len==0)return 0;
	if(len==1){
		int y=b[1]-'a'+1;
		return (1ll*((1ll*sum[k][y]-1ll*sum[x-1][y]*pw[k-x+1]%mod)%mod)+1ll*mod)%mod;
	}
	int cnt=0,cnt1=0,cnt2=0,l=(len+1)/2,r=len/2,ans=0;
	for(int i=1;i<=len;i+=2)d[++cnt]=b[i],cnt1+=b[i]==t[x];
	for(int i=2;i<=len;i+=2)d[++cnt]=b[i],cnt2+=b[i]==t[x];
	for(int i=1;i<=len;++i)b[i]=d[i];
	if(cnt1==l)ans=(1ll*ans+solve(b+l,r,x+1))%mod;
	if(cnt2==r)ans=(1ll*ans+solve(b,l,x+1))%mod;
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&q);
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=2ll*pw[i-1]%mod;
	scanf("%s%s",b0+1,t+1);
	for(int i=1;i<=n;++i){
		int x=t[i]-'a'+1;
		for(int j=1;j<=26;++j){
			sum[i][j]=2ll*sum[i-1][j]%mod;
		}
		sum[i][x]=(1ll*sum[i][x]+1ll)%mod;
	}
	m=strlen(b0+1);
	for(int i=1;i<=q;++i){
		scanf("%d%s",&k,s+1);
		Ans=0;
		for(int j=1;j<=m+1;++j){
			if(pd(j-m))Ans=(1ll*Ans+1ll*solve(c,num,1))%mod;
		}
		printf("%d\n",(1ll*Ans+1ll*mod)%mod);
	}
	return 0;
}
/*
3 1
aaaa
bbd
2 abaaaa
aaaabaaaacaaaabaaaa
*/