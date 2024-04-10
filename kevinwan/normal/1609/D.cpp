#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 1e6+10;
const ll mod = 998244353;

int p[mn],s[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
bool u(int a,int b){
	a=f(a),b=f(b);
	if(a==b)return 0;
	s[a]+=s[b];
	p[b]=a;
	return 1;
}

int a[mn],b[mn];
void solve(){
	int n,d;
	cin>>n>>d;
	iota(p,p+mn,0);
	fill(s,s+mn,1);
	for(int i=0;i<d;i++)cin>>a[i]>>b[i];
	int num=1;
	for(int i=0;i<d;i++){
		if(!u(a[i],b[i]))++num;
		int ans=0;
		vi v;
		for(int j=1;j<=n;j++)if(p[j]==j)v.push_back(s[j]);
		sort(v.begin(),v.end(),greater<int>());
		for(int j=0;j<num;j++)ans+=v[j];
		printf("%d\n",ans-1);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	

	int tc;
	tc=1;
	while(tc--)solve();
}