#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5;
const int PP=14e4;
const long long INF=1e18L+7;
long long p[N+10];
int pot;
long long tree[2*PP+10];
long long xx[2*PP+10];
long long d[N+10];
long long xd[N+10];
long long askx(int l,int r)
{
	long long ans=0;
	for(l+=pot,r+=pot;l<=r;l/=2,r/=2)
	{
		if(l%2==1)
			ans=max(ans,xx[l++]);
		if(r%2==0)
			ans=max(ans,xx[r--]);
	}
	return ans;
}
void add(int x,long long c)
{
	for(x+=pot;x>0;x/=2)
		xx[x]=max(xx[x],c);
	return;
}
long long ask(int l,int r)
{
	long long ans=INF;
	for(l+=pot,r+=pot;l<=r;l/=2,r/=2)
	{
		if(l%2==1)
			ans=min(ans,tree[l++]);
		if(r%2==0)
			ans=min(ans,tree[r--]);
	}
	return ans;
}
vector<int> st;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	for(pot=1;pot<=n;pot*=2);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		p[i]=-p[i];
		p[i]+=b;
		if(p[i]>0)
		{
			xd[i]=p[i];
			st.push_back(i);
		}
		else
		{
			long long tmp=-p[i];
			while(!st.empty() && tmp>0)
			{
				int it=st.back();
				st.pop_back();
				long long xdd=min(xd[it],tmp);
				tmp-=xdd;
				xd[it]-=xdd;
				cerr<<it<<" "<<i<<" "<<xdd<<"\n";
				add(i,xdd+askx(it,i));
				if(xd[it]>0)
					st.push_back(it);
			}
		}
		p[i]+=p[i-1];
		tree[pot+i]=p[i];
	}
	for(int i=pot-1;i>=1;i--)
		tree[i]=min(tree[2*i],tree[2*i+1]);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(p[r]-p[l-1]!=0 || ask(l,r)-p[l-1]<0)
		{
			cout<<"-1\n";
			continue;
		}
		cout<<askx(l,r)<<"\n";
	}
	return 0;
}