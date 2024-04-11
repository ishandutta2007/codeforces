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

int n;
string s[110];
bool czy[12];

map<char, char> xd={{'R', '1'}, {'G', '2'}, {'B', '3'}, {'Y', '4'}, {'W', '5'}};

bool disg(int a, int b){
	return s[a]==s[b] ||
	(s[a][0]!=s[b][0] && (czy[s[a][0]-'0'] || czy[s[b][0]-'0'])) ||
	(s[a][1]!=s[b][1] && (czy[s[a][1]-'0'+5] || czy[s[b][1]-'0'+5]));
}

bool git(int v){
	FOR(i, 1, 10) czy[i]=(v&(1<<(i-1)));
	FOR(i, 1, n) FOR(j, i+1, n) if(!disg(i, j)) return 0;
	return 1;
}

void solve(){
	int ans=10;
	cin>>n;
	FOR(i, 1, n) cin>>s[i], s[i][0]=xd[s[i][0]];
	FOR(i, 0, (1<<10)-1) if(git(i)) ans=min(ans, __builtin_popcount(i));
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}