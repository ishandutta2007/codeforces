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

const int N=2e5+5;

string s, t;
int prevv[N][26], nextt[N][26];
vector<pair<int, char>> vec;

void solve(){
	cin>>s>>t;
	FOR(i, 1, SIZE(s)){
		FOR(j, 0, 25) prevv[i][j]=prevv[i-1][j];
		prevv[i][s[i-1]-'a']=i-1;
	}
	FORD(i, SIZE(s)-2, 0){
		FOR(j, 0, 25) nextt[i][j]=nextt[i+1][j];
		nextt[i][s[i+1]-'a']=i+1;
	}
	int pos=SIZE(s);
	FORD(i, SIZE(t)-1, 0){
		pos=prevv[pos][t[i]-'a'];
		vec.pb({pos, t[i]});
	}
	int lewy=-1, ans=0;
	while(!vec.empty()){
		ans=max(ans, vec.back().st-lewy-1);
		if(lewy==-1) lewy=s[0]==vec.back().nd ? 0 : nextt[lewy+1][vec.back().nd-'a'];
		else lewy=nextt[lewy][vec.back().nd-'a'];
		vec.pop_back();
	}
	ans=max(ans, SIZE(s)-lewy-1);
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}