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

const int N=1e5+5;

int j;
int pi[N], cnt[N];
string s;
vii ans;

void solve(){
	cin>>s;
	s='#'+s;
	FOR(i, 2, SIZE(s)-1){
		while(j && s[i]!=s[j+1]) j=pi[j];
		if(s[i]==s[j+1]) j++;
		pi[i]=j;
		cnt[j]++;
	}
	cnt[SIZE(s)-1]++;
	FORD(i, SIZE(s)-1, 0) cnt[pi[i]]+=cnt[i];
	j=SIZE(s)-1;
	while(j){
		ans.pb({j, cnt[j]});
		j=pi[j];
	}
	cout<<SIZE(ans)<<ent;
	FORD(i, SIZE(ans)-1, 0) cout<<ans[i].st<<sp<<ans[i].nd<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}