#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
const int pot=(1<<19);
const int N=3e5;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
long long t[2*pot+10];
long long read(int x)
{
	long long ans=0;
	for(x+=pot;x>=1;x/=2)
		ans+=t[x];
	return ans;
}
void add(int l,int r,long long c)
{
	for(l+=pot,r+=pot;l<=r;l/=2,r/=2)
	{
		if(l%2==1)
			t[l++]+=c;
		if(r%2==0)
			t[r--]+=c;	
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	long long ans=0;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans+=(long long)x*(i-1)+read(x);
		for(int j=0;x*j<=N;j++)
		{
			add(x*j,min(x*(j+1)-1,N),-j*x);
			ans-=(long long)x*j*(os.order_of_key(x*(j+1))-os.order_of_key(x*j));
		}
		ans+=sum;
		os.insert(x);
		sum+=x;
		cout<<ans<<" \n"[i==n];
	}
	return 0;
}