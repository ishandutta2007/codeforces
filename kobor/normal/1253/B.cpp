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

int n, akt, a;
set<int> jest, byl;
vi ans;

void solve(){
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		if(a<0){
			a=-a;
			if(jest.find(a)==jest.end()){
				cout<<-1<<ent;
				return;
			}
			jest.erase(a);
		}
		else{
			if(byl.find(a)!=byl.end() || jest.find(a)!=jest.end()){
				cout<<-1<<ent;
				return;
			}
			jest.insert(a);
			byl.insert(a);
		}
		akt++;
		if(jest.empty()){
			ans.pb(akt);
			akt=0;
			byl.clear();
		}
	}
	if(!jest.empty()){
		cout<<-1<<ent;
		return;
	}
	cout<<SIZE(ans)<<ent;
	for(auto &x: ans) cout<<x<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}