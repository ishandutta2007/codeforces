// Hydro submission #62c19730cce645725980a233@1656854320833
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod int(1e9+7)
#define It set<odt>::iterator
ll n,m;
ll seed,vmax;
ll a[1000001];
ll rnd()
{
	ll res=seed;
	seed=(seed*7+13)%mod;
	return res;
}
ll qpow(ll a,ll b,ll p)
{
    ll ans=1;
    a%=p;
    while(b)
    {
        if(b&1)
        (ans*=a)%=p;
        (a*=a)%=p;
        b>>=1;
    }
    return ans%p;
}
struct odt
{
	ll l,r;
	mutable ll val;
	bool operator <(const odt &n)const
	{
		return l<n.l;
	}
	odt(ll a,ll b,ll c)
	{
		l=a,r=b,val=c;
	}
	odt(ll a)
	{
		l=a;
	}
};
set<odt> tree;
It split(ll x)
{
	It it=tree.lower_bound(odt(x));
	if(it!=tree.end()&&it->l==x)
	return it;
	it--;
	ll l=it->l,r=it->r,val=it->val;
	tree.erase(it);
	tree.insert(odt(l,x-1,val));
	return tree.insert(odt(x,r,val)).first;
}
void assign(ll l,ll r,ll val)
{
	It it2=split(r+1),it1=split(l);
	tree.erase(it1,it2);
	tree.insert(odt(l,r,val));
}
void add(ll l,ll r,ll val)
{
	It it2=split(r+1),it1=split(l);
	for(It it=it1;it!=it2;it++)
	{
		it->val+=val;
	}
}
ll qsort(ll l,ll r,ll x)
{
	It it2=split(r+1),it1=split(l);
	vector<pair<ll,ll> > p;
	for(It it=it1;it!=it2;it++)
	{
		p.push_back(make_pair(it->val,it->r-it->l+1));
	}
	stable_sort(p.begin(),p.end());
	for(ll i=0;i<p.size();++i)
	{
		x-=p[i].second;
		if(x<=0)
		return p[i].first;
	}
}
ll pow_mod(ll l,ll r,ll x,ll y)
{
	It it2=split(r+1),it1=split(l);
	ll ans=0;
	for(It it=it1;it!=it2;it++)
	{
		ll res=qpow(it->val,x,y)*(it->r-it->l+1);
		res%=y;
		ans+=res;
		ans%=y;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;++i)
	{
		a[i]=rnd()%vmax+1;
		tree.insert(odt(i,i,a[i]));
	}
	tree.insert(odt(n+1,n+1,0));
	while(m--)
	{
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
		if(l>r)
		swap(l,r);
		if(op==3)
		x=rnd()%(r-l+1)+1;
		else
		x=rnd()%vmax+1;
		if(op==4)
		y=rnd()%vmax+1;
		if(op==1)
		add(l,r,x);
		else if(op==2)
		assign(l,r,x);
		else if(op==3)
		printf("%lld\n",qsort(l,r,x));
		else
		printf("%lld\n",pow_mod(l,r,x,y));
	}
	return 0;
}