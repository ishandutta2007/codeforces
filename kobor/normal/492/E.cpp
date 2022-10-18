//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=1e6+5;

int ans[N];
int n, m, dx, dy, x, y, idx;

int fi(int a){
	int res=a;
	for(int i=2; i*i<=a; i++){
		if(a%i==0){
			while(a%i==0) a/=i;
			res-=res/i;
		}
	}
	if(a>1) res-=res/a;
	return res;
}

int pov(int base, int exp){
	if(!exp) return 1;
	if(exp&1) return (ll)base*pov(base, exp^1)%n;
	int pom=pov(base, exp>>1);
	return (ll)pom*pom%n;
}

void solve(){
	cin>>n>>m>>dx>>dy;
	idx=pov(dx, fi(n)-1);
	FOR(i, 1, m){
		cin>>x>>y;
		ans[((y-(ll)x*idx*dy)%n+n)%n]++;
	}
	cout<<0<<sp<<max_element(ans, ans+n)-ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}