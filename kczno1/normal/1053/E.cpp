#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e6+5;
int a[N];
bool ap[N];
deque<int>st,not_used;
int cnt[N];

int n;
void solve(deque<int> q,int rt)
{
	if(q.size()%2==0)
	{
		puts("no");
		exit(0);
	}
	int cnt1=0;
	for(auto x:q)cnt1+=a[x]>0;
	int need=(q.size()+1)/2;
	if(cnt1>need){puts("no");exit(0);}
	for(auto x:q)
	if(!a[x])
	{
		if(cnt1==need)break;
		++cnt1;
		if(not_used.empty()){puts("no");exit(0);}
		a[x]=not_used.back();not_used.pop_back();
	}
	deque<int> st;
	for(auto x:q)
	if(!a[x])
	{
		if(st.size()>=2&&a[st.back()]&&a[st[st.size()-2]])
		{
			st.pop_back();
			a[x]=a[st.back()];
		}
		else st.push_back(x);
	}
	else
	{
		while(st.size()>=2&&a[st.back()]&&!a[st[st.size()-2]])
		{
			st.pop_back();
			a[st.back()]=a[x];
			st.pop_back();
		}
		st.push_back(x);
	}
	for(int i=1;i<st.size();i+=2)a[st[i]]=rt;
}
void solve(int l,int r)
{
	rep(i,l,r)ap[a[i]]=1;
	rep(i,1,n)
	if(!ap[i])not_used.push_back(i);
	else ap[i]=0;
	rep(i,l,r)
	if(!a[i])st.push_back(i);
	else  
	if(!ap[a[i]])
	{
		ap[a[i]]=1;
		st.push_back(i);
	}
	else
	{
		deque<int>nq;
		while(!st.empty()&&a[st.back()]!=a[i])
		{
			nq.push_front(st.back());
			st.pop_back();
		}
		if(st.empty()){puts("no");exit(0);}
		solve(nq,a[i]);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);freopen("1.out","w",stdout); 
#endif
	cin>>n;
	rep(i,1,2*n-1)scanf("%d",a+i);
	if(n==1)
	{
		puts("yes");
		puts("1");
		exit(0);
	}
	if(a[1]&&a[2*n-1])
	{
		if(a[1]!=a[2*n-1])
		{
			puts("no");
			exit(0);
		}
	}
	if(a[1]&&!a[2*n-1])a[2*n-1]=a[1];
	if(!a[1]&&a[2*n-1])a[1]=a[2*n-1];
	if(a[1]||a[2*n-1])
	{
		solve(1,2*n-1);
		puts("yes");
		rep(i,1,2*n-1)printf("%d ",a[i]);
		exit(0);
	}
	solve(2,2*n-2);
	if(not_used.size())
	{
		int rt=not_used.back();not_used.pop_back();
		a[1]=a[2*n-1]=rt;
		solve(st,rt);
	}
	else
	{
		int sz=st.size();
		rep(i,0,sz-1)cnt[i]=(i?cnt[i-1]:0)+(a[st[i]]>0); 
		int i;
		for(i=1;i<sz;i+=2)
		if(a[st[i]]&&cnt[i-1]*2<=i+1&&(cnt[sz-1]-cnt[i])*2<=sz-i)
		{
			int rt=a[st[i]];
			a[1]=a[2*n-1]=rt;
			deque<int>q;
			rep(j,0,i-1)q.push_back(st[j]);
			solve(q,rt);
			q.clear();
			rep(j,i+1,sz-1)q.push_back(st[j]);
			solve(q,rt);
			break;
		}
		if(i>=sz){puts("no");exit(0);}
	}
	puts("yes");
	rep(i,1,2*n-1)printf("%d ",a[i]);
}