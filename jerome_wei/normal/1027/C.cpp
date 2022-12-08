#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
#define INF 0x3f3f3f3f
typedef long long ll;

inline ll sqr(ll x){return x*x;}

template <class T>
inline void read(T &x)
{
	T f=1;x=0;
	char ch=getchar();
	for (;!isdigit(ch) && ch!='-';ch=getchar());
	if (ch=='-')	ch=getchar(),f=-1;
	for (;isdigit(ch);ch=getchar())	x=x*10+ch-'0';
	x*=f;
}

ll ans1,ans2,key1,key2,T,N,tp,st[MAXN],a[MAXN];

inline int check(ll x,ll y)
{
	if (ans1==-1)	return 1;
	return x*ans2 < y*ans1;
}

int main()
{
	read(T);
	while (T--)
	{
		read(N);
		tp=0;
		for (int i=1;i<=N;i++)read(a[i]);
		sort(a+1,a+N+1);
		for (int i=1;i<=N;i++)
		if (a[i]==a[i-1])	st[++tp]=a[i++];
		ans1=ans2=-1;
		for (int i=2;i<=tp;i++)if (check(sqr(st[i]-st[i-1]),st[i]*st[i-1]))
			{
				key1=st[i-1];
				key2=st[i];
				ans1=(st[i]-st[i-1])*(st[i]-st[i-1]);
				ans2=st[i]*st[i-1];
			}
		printf("%lld %lld %lld %lld\n",key1,key1,key2,key2);
	}
	return 0;
}