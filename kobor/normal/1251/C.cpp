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

string s;
queue<char> q[2];

void solve(){
	cin>>s;
	for(auto &x: s) q[x&1].push(x);
	while(!q[0].empty() && !q[1].empty()){
		int pom=(q[0].front()>q[1].front());
		cout<<q[pom].front();
		q[pom].pop();
	}
	FOR(i, 0, 1) while(!q[i].empty()) cout<<q[i].front(), q[i].pop();
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}