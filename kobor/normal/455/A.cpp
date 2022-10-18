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

int cnt[N];
ll dp[N];
int n;

void solve(){
	int a;
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		cnt[a]++;
	}
	dp[1]=cnt[1];
	FOR(i, 2, N-5) dp[i]=max(dp[i-1], (ll)cnt[i]*i+dp[i-2]);
	cout<<dp[N-5]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}