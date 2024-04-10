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
bitset<201010> now,G[26];
int opt,l,r,len,Testing,ans,x,i;
char T[1001010],S[1001010],ch;
int main()
{
	scanf("%s",S);len=strlen(S);
	for (i=0;i<len;i++) G[S[i]-'a'][i]=1;
	Testing=read();
	for (;Testing;Testing--){
		opt=read();
		if (opt==1){
			x=read();x--;ch=getchar();//ch=getchar();
			G[S[x]-'a'][x]=0;G[ch-'a'][x]=1;S[x]=ch;
		}
		if (opt==2){
			l=read();r=read();scanf("%s",T);len=strlen(T);
			if (r-l+1>=len)
			    {
			    	r=r-len+1;
			now.set();now=(now>>(l-1)<<(l-1))^(now>>r<<r);
			for (i=0;i<len;i++) now=now&(G[T[i]-'a']>>i);
			ans=now.count();
			printf("%d\n",ans);
		     }
		     else puts("0");
		}
	}
return 0;
}