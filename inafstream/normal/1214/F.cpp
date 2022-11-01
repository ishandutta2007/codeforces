#include <bits/stdc++.h>
using namespace std;

const long long add=200000;
long long ans,cur,dlt,n,len,i,j,dif[400005],cnta[400005],cntb[400005],flga[400005],flgb[400005],val[400005],lnk[400005];
stack<long long> sa,sb;

struct _a
{
	long long id,x;
}a[400005];
struct _b
{
	long long id,x;
}b[400005];
bool cmpa(_a x,_a y)
{
	return x.x<y.x;
}
bool cmpb(_b x,_b y)
{
	return x.x<y.x;
}

struct evt
{
	long long typ,x,id;
};
vector<evt> seq;

int main()
{
	scanf("%I64d%I64d",&len,&n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i].x);
		a[i].id=i;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&b[i].x);
		b[i].id=i;
	}
	
	sort(a+1,a+n+1,cmpa);
	sort(b+1,b+n+1,cmpb);
	ans=(n+1)*(len+1);
	
	i=1;j=1;
	while (i<=n||j<=n)
	{
		if (i<=n&&((j>n)||a[i].x<b[j].x))
		{
			seq.push_back((evt){1,a[i].x,i});
			i++;
		}
		else
		{
			seq.push_back((evt){-1,b[j].x,j});
			j++;
		}
	}
	i=1;j=1;
	while (i<=n||j<=n)
	{
		if (i<=n&&((j>n)||a[i].x<b[j].x))
		{
			seq.push_back((evt){1,a[i].x+len,i});
			i++;
		}
		else
		{
			seq.push_back((evt){-1,b[j].x+len,j});
			j++;
		}
	}
	
	for (i=0;i<=add*2;i++)
	{
		flga[i]=flgb[i]=1;
	}
	
	for (i=0;i<n*2;i++)
	{
		if (i) dif[i]=dif[i-1];
		if (seq[i].typ==1)
		{
			dif[i]++;
			if (dif[i]>0) val[i]=-seq[i].x; else val[i]=seq[i].x;
			cur+=val[i];
			cnta[add+dif[i]]+=val[i];
		}
		else
		{
			dif[i]--;
			if (dif[i]<0) val[i]=-seq[i].x; else val[i]=seq[i].x;
			cur+=val[i];
			cntb[add+dif[i]]+=val[i];
		}
	}
	
	int pos=0,df=0,way=-1;
	for (i=0;i<n*2;i++)
	{
		if (ans>cur){ans=cur;way=i;}
		if (seq[i].typ==1)
		{
			cnta[add+dif[i]]-=flga[add+dif[i]]*val[i];
			cur-=flga[add+dif[i]]*val[i];
		}
		else
		{
			cntb[add+dif[i]]-=flgb[add+dif[i]]*val[i];
			cur-=flgb[add+dif[i]]*val[i];
		}
		if (seq[i].typ==1)
		{
			cur-=cnta[add+pos+1]*2;cur-=cntb[add+pos]*2;
			cnta[add+pos+1]*=-1;cntb[add+pos]*=-1;
			flga[add+pos+1]*=-1;flgb[add+pos]*=-1;
		}
		else
		{
			cur-=cnta[add+pos]*2;cur-=cntb[add+pos-1]*2;
			cnta[add+pos]*=-1;cntb[add+pos-1]*=-1;
			flga[add+pos]*=-1;flgb[add+pos-1]*=-1;
		}
		pos+=seq[i].typ;
		long long tmp=seq[i+n*2].x;
		cur+=tmp;
		if (seq[i].typ==1) cnta[add+pos]+=tmp; else cntb[add+pos]+=tmp;
	}
	
	printf("%I64d\n",ans);
	
	for (i=way;i<way+n+n;i++)
	{
//		cerr<<seq[i].id<<endl;
		if (seq[i].typ==1)
		{
			if (sb.empty()) sa.push(seq[i].id);
			else
			{
				lnk[a[seq[i].id].id]=b[sb.top()].id;
				sb.pop();
			}
		}
		else
		{
			if (sa.empty()) sb.push(seq[i].id);
			else
			{
				lnk[a[sa.top()].id]=b[seq[i].id].id;
				sa.pop();
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		printf("%I64d ",lnk[i]);
	}
	return 0;
}