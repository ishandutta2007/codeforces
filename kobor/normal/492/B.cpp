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

int t[1010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, l;
	double ans;
	cin>>n>>l;
	FOR(i, 1, n) cin>>t[i];
	sort(t+1, t+n+1);
	ans=(double)max(t[1], l-t[n]);
	FOR(i, 2, n) ans=max(ans, (double)(t[i]-t[i-1])/2);
	cout<<fixed<<setprecision(2);
	cout<<ans<<ent;
	return 0;
}