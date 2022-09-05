#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=5e5+5;
priority_queue<s64,vector<s64>,greater<s64> >heap;
s64 g[N];
int i,mj;

void ins(int v,int c)
{
	int j1=min((i-min(c,i))/2,mj);
	int m1=j1+min(c,i);
//	if(i==5)cerr<<"j1="<<j1<<"m1="<<m1<<endl;
	per(j,mj,j1)
	{
		g[j]=heap.top();
		heap.pop();
	}
	rep(j,mj+1,m1+1)g[j]=0;
		int l=j1;
		while(g[l+1]>v)++l;
		int j=l;
		s64 sum=0;
		rep(nj,l+1,m1)
		{
			while(i-j-nj<0)
			{
				assert(j>=j1); 
				sum+=g[j];
				--j;
			}
			g[nj+1]+=g[nj];
			g[nj]=max(g[nj],(s64)(nj-j)*v-sum);		
			g[nj+1]-=g[nj];
			sum+=g[nj];
		}
		rep(j,j1,m1)heap.push(g[j]);
	
	i+=c;mj=m1;
//	cerr<<"v="<<v<<"c="<<c<<endl;
//	rep(j,1,mj)fprintf(stderr,"%lld%c",g[j]," \n"[j==mj]);
}

int main()
{
#ifdef kcz	
	freopen("1.in","r",stdin);
#endif	
	int n;
	cin>>n;

	map<int,int>c;
	s64 sum=0;
	rep(i,1,n)
	{
		int x;
		scanf("%d",&x);
		++c[x];
		sum+=x;
	}
	
	heap.push(g[0]=1e9+5);
	for(auto pr=c.end();pr!=c.begin();)
	{
		--pr;
		ins(pr->first,pr->second);
	}
	
	s64 ans=0;
	rep(i,1,mj)
	{
		ans+=max(0LL,heap.top());
		heap.pop();
	}
	cout<<sum-ans<<endl;
}