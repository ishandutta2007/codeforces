#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 1e6+10;
const ll mod = 1e9+7;
const int SIZE = 400;

int a[mn];
ll ans[mn],num[mn],cur;
struct query{
	int l,r,ind;
};
vector<query>v;

void add(int x){
	cur+=x*(2*num[x]+1);
	num[x]++;
}
void sub(int x){
	num[x]--;
	cur-=x*(2*num[x]+1);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)cin>>a[i];
	v.resize(t);
	for(int i=0;i<t;i++)cin>>v[i].l>>v[i].r,v[i].ind=i;
	sort(v.begin(),v.end(),[](const query &a,const query &b){
		if(a.l/SIZE!=b.l/SIZE)return a.l/SIZE<b.l/SIZE;
		return a.r<b.r;
	});
	int l=1,r=0;
	for(query q:v){
		while(l<q.l)sub(a[l++]);
		while(l>q.l)add(a[--l]);
		while(r<q.r)add(a[++r]);
		while(r>q.r)sub(a[r--]);
		ans[q.ind]=cur;
	}
	for(int i=0;i<t;i++)printf("%lld\n",ans[i]);
}