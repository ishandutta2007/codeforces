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

const int N=1e5+5;

ii t[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, r;
	ll avg, ans=0;
	cin>>n>>r>>avg;
	avg*=n;
	FOR(i, 1, n) cin>>t[i].nd>>t[i].st;
	sort(t+1, t+n+1);
	FOR(i, 1, n) avg-=t[i].nd;
	FOR(i, 1, n){
		if(avg<=0) break;
		ans+=min((ll)r-t[i].nd, avg)*t[i].st;
		avg-=r-t[i].nd;
	}
	cout<<ans<<ent;
	return 0;
}