#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long l,r,L,R,MOD,now,pw,tot,ans,lft,rit;
long long calc(long long x){
	if (x==0) return 0;
	now=1;pw=1;tot=0;ans=0;
	lft=0;rit=0;
	while (tot<x){
		if (tot+pw>=x){
			pw=x-tot;
		    if (now&1)   {ans=ans+(pw % MOD)*((2*lft+pw) % MOD) % MOD;lft+=pw;}
		    else {ans=ans+(rit+1+rit+pw) % MOD*(pw % MOD) % MOD;rit+=pw;}
		    ans%=MOD;
			break;
		}
		if (now&1) {ans=ans+(pw % MOD)*((2*lft+pw) % MOD) % MOD;lft+=pw;}
		else {ans=ans+(rit+1+rit+pw) % MOD*(pw % MOD) % MOD;rit+=pw;}
		//(lft+pw)*(lft+pw)-lft*lft
		ans%=MOD;
		tot=tot+pw;
		pw=pw*2;now=now+1;
	}
}
int main()
{
	l=read();r=read();MOD=1e9+7;
	R=calc(r);L=calc(l-1);
	printf("%lld\n",(R-L+MOD) % MOD);
    return 0;
}