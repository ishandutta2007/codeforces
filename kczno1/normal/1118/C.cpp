#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=20+1;
int ans[N][N];
map<int,int>c;
priority_queue<pii>heap;

int main()
{
#ifdef kcz
//	freopen("1.in","r",stdin); 
#endif
	int n;
	cin>>n;
	rep(i,1,n*n)
	{
		int x;
		cin>>x;
		++c[x];
	}
	for(auto p:c)heap.push({p.second,p.first});
	rep(i,1,n/2)
	rep(j,1,n/2)
	{
		auto p=heap.top();heap.pop();
		ans[i][j]=ans[n-i+1][n-j+1]=ans[n-i+1][j]=ans[i][n-j+1]=p.second;
		p.first-=4;
		heap.push(p);
	}
	if(n%2)
	{
		rep(i,1,n/2)	
		{
			auto p=heap.top();heap.pop();
			ans[n/2+1][i]=ans[n/2+1][n-i+1]=p.second;
			p.first-=2;
			heap.push(p);
			
			p=heap.top();heap.pop();
			ans[i][n/2+1]=ans[n-i+1][n/2+1]=p.second;
			p.first-=2;
			heap.push(p);
		}
		auto p=heap.top();heap.pop();
		ans[n/2+1][n/2+1]=p.second;
		p.first-=1;
		heap.push(p);
	}
	while(!heap.empty())
	{
		if(heap.top().first<0)
		{
			puts("NO");
			exit(0);
		}
		heap.pop();
	}
	puts("YES");
	rep(i,1,n)
	rep(j,1,n)printf("%d%c",ans[i][j]," \n"[j==n]);	
}