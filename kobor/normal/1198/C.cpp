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

int n, m, a, b, ile;
set<int> s;
vi match;

void solve(){
	cin>>n>>m;
	s.clear(); match.clear();
	FOR(i, 1, n*3) s.insert(i);
	FOR(i, 1, m){
		cin>>a>>b;
		if(s.find(a)!=s.end() && s.find(b)!=s.end()){
			match.pb(i);
			s.erase(a);
			s.erase(b);
		}
	}
	ile=0;
	if(SIZE(s)>=n){
		cout<<"IndSet"<<ent;
		for(auto &x: s){
			cout<<x<<sp;
			ile++;
			if(ile==n) break;
		}
	}
	else{
		cout<<"Matching"<<ent;
		for(auto &x: match){
			cout<<x<<sp;
			ile++;
			if(ile==n) break;
		}
	}
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt) solve();
	return 0;
}