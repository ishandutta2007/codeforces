#include<bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
inline ll read()
{
    char s;
    ll k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(isdigit(s)){k=k*10+(s^'0');s=getchar();}
    return k*base;
}
inline void write(int x)
{
    static char cnt,num[15];cnt=0;
    if (!x)
    {
        printf("0");
        return;
    }
    for (;x;x/=10) num[++cnt]=x%10;
    for (;cnt;putchar(num[cnt--]+48));
}
const int Maxn=3e5+20;
const int maxp=1.5e7;
int prime[maxp+20],P1[maxp+20],tot,d[maxp+20];
inline void work()
{
	for (int i=2;i<=maxp;i++)
	{
		if(!P1[i])prime[++tot]=i,d[i]=i;
		for(int j=1;j<=tot && i*prime[j]<=maxp;j++)
		{
			int k=i*prime[j];
			P1[k]=1; d[k]=prime[j];
			if(!(i%prime[j]))break;
		}
	}
}

int a[Maxn],n;
int tag[maxp];
int main()
{
	work();
	n=read();
	int D1=0;
	for (int i=1;i<=n;i++) 
	{
		a[i]=read(),D1=__gcd(D1,a[i]);
	}
	for (int i=1;i<=n;i++) a[i]/=D1;

	for (int i=1;i<=n;i++)
	{
		int u=a[i];
		while(u>1)
		{
			int p=d[u];
			while(!(u%p))u/=p;
			tag[p]++;
		}
	}
	int ans=0;
	for (int i=1;i<=maxp;i++) if(tag[i]<n) ans=max(ans,tag[i]);
	if(ans==0) cout<<-1;
	else printf("%d\n",n-ans);
	return 0;
}