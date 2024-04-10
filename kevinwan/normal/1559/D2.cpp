#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
mt19937_64 rng(time(0));

const int mn = 3e5+10;
const ll mod = 1e9+7;

multiset<pii>ms;

struct dsu {
	int p[mn],s[mn];
	dsu(){
		iota(p,p+mn,0);
		fill(s,s+mn,1);
	}
	int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
	void mrg(int a,int b){
		a=f(a),b=f(b);
		if(a==b)return;
		ms.erase(ms.find({s[a],a}));
		ms.erase(ms.find({s[b],b}));
		if(s[a]<s[b])swap(a,b);
		s[a]+=s[b],p[b]=a;
		ms.insert({s[a],a});
	}
} d1, d2;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)ms.insert({1,i}),ms.insert({1,i});
	for(int i=0;i<m1;i++){
		int a,b;
		cin>>a>>b;
		d1.mrg(a,b);
	}
	for(int i=0;i<m2;i++){
		int a,b;
		cin>>a>>b;
		d2.mrg(a,b);
	}
	int num=n-max(m1,m2)-1;
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		int x=ms.begin()->second,y;
		while(true){
			y=rng()%n+1;
			if(d1.f(x)!=d1.f(y)&&d2.f(x)!=d2.f(y))break;
		}
		printf("%d %d\n",x,y);
		d1.mrg(x,y);
		d2.mrg(x,y);
	}
}