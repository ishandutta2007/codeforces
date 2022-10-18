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

const int N=1e6+5;

int t[N], n, jak, pos=1; //jak = 0 wieksze rowne, 1 mniejsze
ll dp[N];

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 2, n){
		if((jak==0 && t[i]<t[i-1]) || (jak==1 && t[i]>=t[i-1])){
			jak^=1;
			pos=i-1;
		}
		dp[i]=max(dp[pos]+abs(t[i]-t[pos+1]), dp[pos-1]+abs(t[i]-t[pos]));
	}
	cout<<dp[n]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}