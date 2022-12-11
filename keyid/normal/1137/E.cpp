#include <bits/stdc++.h>
using namespace std;

const int MAXM=300005;

typedef long long LL;

struct car
{
	int id;
	LL head_sum,b_sum,s_sum;
}q[MAXM*2];

LL nowb,nows,nowhead;

LL get_val(const car &c)
{
	return nowb-c.b_sum+c.id*(nows-c.s_sum)-(nowhead-c.head_sum);
}

LL cal(const car &a,const car &b)
{
	LL va=get_val(a),vb=get_val(b);
	if (va<=vb)
		return 0;
	return (va-vb-1)/(b.id-a.id)+1;
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	int head=MAXM,tail=MAXM,mnid=0,mxid=n-1;
	q[head]={0,0,0,0};
	while (m--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int k;
			scanf("%d",&k);
			mnid-=k;
			q[--head]={mnid,nowhead,nowb,nows};
			while (head<tail&&cal(q[head],q[head+1])<=0)
			{
				q[head+1]=q[head];
				head++;
			}
			while (head+2<=tail&&cal(q[head],q[head+1])<=cal(q[head+1],q[head+2]))
			{
				q[head+1]=q[head];
				head++;
			}
		}
		else if (op==2)
		{
			int k;
			scanf("%d",&k);
			q[++tail]={mxid+1,nowhead,nowb,nows};
			mxid+=k;
			if (cal(q[tail-1],q[tail])<=0)
				tail--;
			else while (tail-2>=head&&cal(q[tail-2],q[tail-1])<=cal(q[tail-1],q[tail]))
			{
				q[tail-1]=q[tail];
				tail--;
			}
		}
		else
		{
			int b,s;
			scanf("%d%d",&b,&s);
			nowb+=b;
			nows+=s;
			nowhead+=(LL)mnid*s;
		}
		while (head<tail&&cal(q[tail-1],q[tail])<=0)
			tail--;
		printf("%d %lld\n",q[tail].id-mnid+1,get_val(q[tail]));
	}
	return 0;
}