#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int n,a[N];bool vis[N];
vector<vector<int> >ans;

void work(int k)
{
	static vector<int> arr[N];
	static int fr[N];
	arr[0].resize(1);
	int top=0;
	rep(i,1,n)
	if(!vis[i])
	{
		int l=0,r=top+1;
		while(l+1!=r)
		{
			int mid=(l+r)/2;
			if(a[i]>a[arr[mid].back()])l=mid;
			else r=mid;
		}
		fr[i]=arr[l].back();
		if(r>top)arr[++top].clear();
		arr[r].push_back(i);
	}
	if(!top)return ;
	if(top>=k)
	{
		vector<int>now;
		for(int x=arr[top].front();x;x=fr[x]){now.push_back(x);vis[x]=1;}
		reverse(now.begin(),now.end());
		ans.push_back(now);
		work(k-1);
	}
	else
	{
		rep(i,1,top)ans.push_back(arr[i]);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		scanf("%d",&n);
		rep(i,1,n){scanf("%d",a+i);vis[i]=0;}
		int k=0;
		while(k*(k-1)/2<n)++k;
		ans.clear();
		work(k-1);
		printf("%d\n",int(ans.size()));	
		for(auto arr:ans)
		{
			printf("%d",int(arr.size()));
			for(auto pos:arr)printf(" %d",a[pos]);
			puts("");	
		}
	}
}