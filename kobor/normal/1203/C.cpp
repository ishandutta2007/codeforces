//Krzysztof Boryczka
#pragma GCC optimize "O3"
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

const int N=4e5+5;

int n;
ll t[N], val;

int divs(ll a){
	int ret=1, cnt;
	for(int i=2; (ll)i*i<=a; i++){
		cnt=1;
		while(a%i==0){
			a/=i;
			cnt++;
		}
		ret*=cnt;
	}
	if(a>1) ret*=2;
	return ret;
}

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	val=t[1];
	FOR(i, 2, n) val=__gcd(val, t[i]);
	cout<<divs(val)<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}