#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+99;
ll n,t,ans;
pair<ll,ll> a[N];
ll solve(ll x,ll y){
	ll p=x,sum=0,an=0,g;
	set<ll> s;
	map<ll,ll> tedad;
	f(i,a[x].F,a[x].F+y-x+1){
		while(a[p].F==i && p<n){
			s.insert(a[p].S);
			tedad[a[p].S]++;
			sum+=a[p].S;
			p++;
		}
		ll max_element=*(s.rbegin());
		//cout<<max_element<<endl;
		sum-=max_element;	
		tedad[max_element]--;
		if(tedad[max_element]==0)
 	   	s.erase(max_element);
 	   an+=sum;
	}
	return an;
}
int main(){
	get(n);
	f(i,0,n) get(a[i].F);
	f(i,0,n) get(a[i].S);
	sort(a,a+n);
	ll i=0,j;

	while(i<n){
		j=n;
		f(l,i+1,n){
			if(a[l].F!=a[l-1].F && a[i].F+l-i<a[l].F){
				j=l;
				break;
			}
		}
		ans+=solve(i,j-1);
		i=j;
	}
	cout<<ans<<endl;
}