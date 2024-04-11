//Krzysztof Boryczka
#pragma GCC optimize("O3")
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

string a, b;
int pref[N];
int sum, ans;

void solve(){
	cin>>a>>b;
	a='#'+a;
	for(auto &x: b) sum+=x-'0';
	FOR(i, 1, SIZE(a)-1) pref[i]=pref[i-1]+a[i]-'0';
	FOR(i, SIZE(b), SIZE(a)-1) if(!((pref[i]-pref[i-SIZE(b)]+sum)&1)) ans++;
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}