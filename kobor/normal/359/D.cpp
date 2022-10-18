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

const int N=3e5+5;

int n, maks=-1;
int t[N];
vi ans;

void solve(){
	int l, r;
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	for(int i=1; i<=n; i=r+1){
		l=r=i;
		while(l>1 && t[l-1]%t[i]==0) l--;
		while(r<n && t[r+1]%t[i]==0) r++;
		if(r-l>maks){
			maks=r-l;
			ans.clear();
		}
		if(r-l==maks) ans.pb(l);
	}
	cout<<SIZE(ans)<<sp<<maks<<ent;
	for(auto &x: ans) cout<<x<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}