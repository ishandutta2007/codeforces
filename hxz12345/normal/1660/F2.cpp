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
long long i,n,lft,rit,pre[1001010],tree[4][1001010],ans;
char S[1001010];
void modify(int opt,int x,int val){for (;x;x-=x&-x) tree[opt][x]+=val;}
long long query(int opt,int x){long long ans=0;for (;x<=800000;x+=x&-x) ans+=tree[opt][x];return ans;}
int main()
{
	for (int Testing=read();Testing;Testing--){
		n=read();scanf("%s",S+1);pre[0]=0;
		for (i=1;i<=n;i++) pre[i]=pre[i-1]+(S[i]=='-');ans=0;
		for (i=0;i<=n;i++) pre[i]=pre[i]*2-i+400000;
		for (rit=n;rit>=0;rit--){
			ans+=query(pre[rit] % 3,pre[rit]);
			modify(pre[rit] % 3,pre[rit],1);
		}
		for (i=0;i<=n;i++) modify(pre[i] % 3,pre[i],-1);
		printf("%lld\n",ans);
		}
return 0;
}