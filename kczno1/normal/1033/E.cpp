#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=600+5;
int n,fa[N],deep[N];
deque<int>q;
void push(int x,int fr)
{
	fa[x]=fr;deep[x]=deep[fr]+1;
	q.push_back(x);
}
int query(vector<int> q)
{
	int m=q.size();
	if(m<=1)return 0;
	printf("? %d\n",m);
	rep(i,0,m-1)printf("%d%c",q[i]," \n"[i==m-1]);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
void check(int x,vector<int> nq)
{
	int m=nq.size();
	int c0=query(nq);
	nq.push_back(x);
	int c1=query(nq);
	if(c0==c1)return ;
	if(m==1){push(nq.front(),x);return ;}
	int m1=m/2;
	vector<int>q1,q2;
	rep(i,0,m1-1)q1.push_back(nq[i]);
	rep(i,m1,m-1)q2.push_back(nq[i]);
	check(x,q1);
	check(x,q2);
}

void check(vector<int> a)
{
	if(!query(a))return ;
	int l=1,r=a.size();
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		vector<int>a1=a;
		a1.resize(mid);
		if(query(a1))r=mid;
		else l=mid;
	}
	
	a.resize(r);
	reverse(a.begin(),a.end());
	l=1;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		vector<int>a1=a;
		a1.resize(mid);
		if(query(a1))r=mid;
		else l=mid;
	}
	
	int x=a[0],y=a[r-1];
	vector<int>qx,qy;
	while(x!=y)
	if(deep[x]>deep[y])
	{
		qx.push_back(x);x=fa[x];
	}
	else
	{
		qy.push_back(y);y=fa[y];
	}
	
	puts("N");
	printf("%d\n",int(qx.size()+qy.size()+1));
	for(auto x:qx)printf("%d ",x);
	printf("%d ",x);
	reverse(qy.begin(),qy.end());
	for(auto x:qy)printf("%d ",x);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n;
	memset(deep,-1,sizeof(deep));
	push(1,0);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		vector<int>nq;
		rep(y,1,n)
		if(deep[y]==-1)nq.push_back(y);
		check(x,nq);
	}
	vector<int>ans[2];
	rep(i,1,n)ans[deep[i]%2].push_back(i);
	check(ans[0]);
	check(ans[1]);
	puts("Y");
	printf("%d\n",int(ans[0].size()));
	for(auto x:ans[0])printf("%d ",x);
}