#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=100500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int pr[N];
bool prz[N];
void Pre(int n)
{
	fo(i,2,n)
	{
		if(!prz[i])pr[++pr[0]]=i;
		fo(j,1,pr[0])
		{
			int t=i*pr[j];
			if(t>n)break;
			prz[t]=1;
			if(i%pr[j]==0)break;
		}
	}
}
int CNT=0;
bool z[N];
int ASKA(int q)//////////////////////////////
{
	printf("A %d",q);
	cout<<endl;
	read(q);
	return q;
}
int ASKB(int q)//////////////////////////////
{
	printf("B %d",q);
	cout<<endl;
	read(q);
	return q;
}
// int ASKA(int q)//////////////////////////////
// {
// 	++CNT;
// 	int ans=0;
// 	for(int i=q;i<=n;i+=q)
// 	{
// 		ans+=(!z[i]);
// 	}
// 	return ans;
// }
// int ASKB(int q)//////////////////////////////
// {
// 	++CNT;
// 	int ans=0;
// 	for(int i=q;i<=n;i+=q)
// 	{
// 		ans+=(!z[i]);
// 		if(i!=m)z[i]=1;
// 	}
// 	return ans;
// }
int main()
{
	// freopen("!.in","r",stdin);
	// freopen("1.out","w",stdout);
	int q,w,_;
	read(n);

	// read(m);//////////////////////////

	Pre(n);
	fo(i,1,pr[0])
	{
		if(pr[i]*pr[i]>n)break;
		ASKB(pr[i]);
	}
	ans=1;
	int LI;
	fo(i,1,pr[0])
	{
		LI=i;
		if(pr[i]*pr[i]>n)break;
		if(!ASKB(pr[i]))continue;
		for(ans*=pr[i];ans*pr[i]<=n;ans*=pr[i])if(!ASKB(ans*pr[i]))break;
	}
	if(ans==1)
	{
		q=ASKA(1);
		int cnt=0;
		fo(i,LI,pr[0])
		{
			++cnt;
			--q;
			ASKB(pr[i]);
			if(cnt==100||i==pr[0])
			{
				cnt=0;
				w=ASKA(1);
				if(q!=w)
				{
					fod(j,i,1)if(ASKA(pr[j])){ans=pr[j];break;}
					break;
				}
			}
		}
	}else{
		fo(i,LI,pr[0])
		{
			if((LL)pr[i]*ans>n)break;
			if(ASKB((LL)ans*pr[i]))ans*=pr[i];
		}
	}
	printf("C %d\n",ans);

	return 0;
/////////////////////////////
	if(ans!=m||CNT>=10000)
	{
		printf("WAWAWA!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("WAWAWA!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("WAWAWA!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("WAWAWA!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("%d\n",CNT);/////////////
		while(1);
	}
	return 0;
}