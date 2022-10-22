#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; bool flag[1100000];
ll C,a[1100000],d[1100000],w[1100000],v[1100000];
set<ll> s;
int main(){
	scanf("%d%lld",&n,&C);
	for (int i=1;i<=n-2;i++) scanf("%lld",&w[i]);
	ll l=0,r=w[1],op=1,sum=0;
	for (int i=2;i<=n-2;i++){
		if (l<=w[i]&&w[i]<=r||s.find((w[i]-sum)/op)!=s.end()){
			flag[i]=true;
			l=0; r=w[i];
			s.clear(); op=1; sum=0;
			continue;
		}
		while (!s.empty()){
			ll x=(op==1?*s.begin():*s.rbegin());
			if (op*x+sum>=0) break;
			s.erase(x);
		}
		while (!s.empty()){
			ll x=(op==1?*s.rbegin():*s.begin());
			if (op*x+sum<=w[i]) break;
			s.erase(x);
		}
		v[i]=l; l=w[i]-l; r=max(0ll,w[i]-r); swap(l,r);
		if (l>r&&s.empty()){
			puts("NO");
			return 0;
		}
		if (l>r) v[i]=op*(*s.begin())+sum,l=-2,r=-3;
		op=-op; sum=w[i]-sum; s.insert((w[i]-sum)/op);
	}
	if (l<=r) d[n-2]=l;
	else d[n-2]=op*(*s.begin())+sum;
	for (int i=n-2;i>1;i--)
		if (flag[i]) d[i-1]=w[i];
		else d[i-1]=(d[i]==w[i]?v[i]:w[i]-d[i]);
	
	a[3]=w[1]; a[2]=a[3]-d[1];
	for (int i=4;i<=n;i++){
		a[i]=a[i-1]+d[i-2];
		if (max(a[i],max(a[i-1],a[i-2]))-min(a[i],min(a[i-1],a[i-2]))!=w[i-2]) a[i]=a[i-1]-d[i-2];
		if (max(a[i],max(a[i-1],a[i-2]))-min(a[i],min(a[i-1],a[i-2]))!=w[i-2]) return 233;
	}

	ll mn=0;
	for (int i=1;i<=n;i++) mn=min(mn,a[i]);
	puts("YES");
	for(int i=1;i<=n;i++) printf("%lld ",a[i]-mn);
	return 0;
}