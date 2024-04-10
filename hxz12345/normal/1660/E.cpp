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
char S[1001010];
long long i,j,n,tot,a[2010][2010],K,P1,P2,G;
int main()
{
	for (int Testing=read();Testing;Testing--){
		n=read();tot=0;
		for (i=1;i<=n;i++){
			scanf("%s",S+1);
			for (j=1;j<=n;j++) a[i][j]=S[j]-'0',tot+=a[i][j];
		}
		K=0;
		for (i=1;i<=n;i++){
			P1=0;
			for (j=1;j<=n;j++)
			     P1+=a[j][(j+i-1) % n+1];
			K=max(K,P1);
		}
		printf("%lld\n",n-K+tot-K);
		//a[i][i] 1=K
		//tot-K+(n-K)=tot+n-2*K
	}
return 0;
}