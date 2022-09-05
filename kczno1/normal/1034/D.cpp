#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
typedef long long s64;
typedef pair<int,int> pii;
typedef pair<s64,s64> pll;
const int N=3e5+5,U=1e9+5;
int n,k;
vector<pii>lk[N];
namespace GET_LK
{
map<int,int>mp;
void split(int x)
{
//	cerr<<(--mp.lower_bound(x+1))->first<<" "<<((--mp.lower_bound(x+1))->second)<<endl;
	mp.insert(pii(x,(--mp.lower_bound(x+1))->second));
//	cerr<<mp[x]<<endl;
}
void main()
{
	mp[0]=0;mp[U+2]=0;
	rep(i,1,n)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		--r;
		split(l);
		split(r+1);
		while(1)
		{
			auto it=mp.lower_bound(l);
			if(it->first>r)break;
		//	cerr<<(it->first)<<" "<<(it->second)<<endl;
			auto it_next=it;++it_next;
			lk[i].push_back(pii(it->second+1,(it_next->first)-(it->first))); 
			mp.erase(it);
		}
		mp[l]=i;
	}
}
};
namespace ERFEN
{
s64 ad[N];
pll check(int mid)
{
	rep(i,1,n+1)ad[i]=0;
	pll ans=pll(0,0);
	int j=1;s64 sum=0,point=0;
	rep(i,1,n)
	{
		auto add=[&](int x,int v)
		{
			sum+=s64(max(0,j-x))*v;
			if(x<=j)point+=v;
			else ad[x]+=v;
		};
		for(auto pr:lk[i])
		{
			add(pr.first,pr.second);
			add(i+1,-pr.second);
		}
		while(point>=mid)
		{
			sum+=point;
			++j;
			point+=ad[j]; 
		}
		ans.first+=j-1;
		ans.second+=sum;
	}
	return ans;
}
void main()
{
	int l=0,r=U;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(check(mid).first>=k)l=mid;
		else r=mid;
	}
	pll ans=check(l);
	cout<<ans.second-(ans.first-k)*l;
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	cin>>n>>k;
	GET_LK::main();
	ERFEN::main();
}