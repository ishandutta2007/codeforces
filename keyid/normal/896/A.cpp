#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=100005;
const LL INF=0x3f3f3f3f3f3f3f3fLL;

const char f0[200]={"What are you doing at the end of the world? Are you busy? Will you save us?"};
const char p1[200]={"What are you doing while sending \""};
const char p2[200]={"\"? Are you busy? Will you send \""};
const char p3[200]={"\"?"};
LL len[MAXN];
int lp[5];

char query(int n,LL k)
{
	if (n==0)
		return f0[k-1];
	if (k<=lp[1])
		return p1[k-1];
	k-=lp[1];
	if (k<=len[n-1])
		return query(n-1,k);
	k-=len[n-1];
	if (k<=lp[2])
		return p2[k-1];
	k-=lp[2];
	if (k<=len[n-1])
		return query(n-1,k);
	k-=len[n-1];
	return p3[k-1];
}

int main()
{
	lp[1]=strlen(p1);
	lp[2]=strlen(p2);
	lp[3]=strlen(p3);
	len[0]=strlen(f0);
	for (int i=1;i<=100000;i++)
	{
		len[i]=lp[1]+lp[2]+lp[3]+len[i-1]*2;
		if (len[i]>INF)
			len[i]=INF;
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int n;
		LL k;
		scanf("%d%lld",&n,&k);
		if (len[n]<k)
			putchar('.');
		else
			putchar(query(n,k));
	}
	return 0;
}