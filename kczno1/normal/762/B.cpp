#include<algorithm>
#include<cstdio>
using namespace std;

#define ll long long
#define N 600100
int q1[N],h1,n1,q2[N],h2,n2;
int num;
ll ans;

ll sum(int *l,int *r)
{
	ll ans=0;
	while (l<=r) ans+=*(l++);
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int m;
	scanf("%d",&m);
	int cnt;char ch[10];
	while (m--) 
	{scanf("%d%s",&cnt,ch);
	 if (ch[0]=='U') q1[++n1]=cnt;
	 else q2[++n2]=cnt;
	}

	h1=min(a,n1);
	if(n1&&h1) nth_element(q1+1,q1+h1,q1+n1+1);
	h2=min(b,n2);
	if(n2&&h2) nth_element(q2+1,q2+h2,q2+n2+1);
	num=h1+h2;
	ans=sum(q1+1,q1+h1)+sum(q2+1,q2+h2);
	
	while ((++h2)<=n2) q1[++n1]=q2[h2];
	++h1;
	h2=min(n1-h1+1,c);
	if(h2&&h1<=n1) nth_element(q1+h1,q1+h1+h2-1,q1+n1+1);
	num+=h2;
	ans+=sum(q1+h1,q1+h1+h2-1);
	printf("%d %lld",num,ans);
}