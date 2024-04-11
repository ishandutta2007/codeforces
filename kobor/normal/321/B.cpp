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

int n, m, a, ans;
multiset<int> moje, moje2;
vi jdef, joff;
string s;

void przebijdefa(){
	for(auto &x: jdef){
		if(!SIZE(moje)) return;
		auto u=moje.upper_bound(x);
		if(u==moje.end()) moje.clear();
		else moje.erase(u);
	}
}

int przebijofa(){
	int ret=0;
	for(auto &x: joff){
		if(!SIZE(moje)) return 0;
		auto u=moje.lower_bound(x);
		if(u==moje.end()) moje.clear();
		else{
			ret+=*u-x;
			moje.erase(u);
		}
	}
	for(auto &x: moje) ret+=x;
	return ret;
}

int tylkofa(){
	int ret=0;
	reverse(joff.begin(), joff.end());
	for(auto &x: joff){
		if(!SIZE(moje2)) return ret;
		auto u=prev(moje2.end());
		ret+=max(*u-x, 0);
		moje2.erase(u);
	}
	return ret;
}

void solve(){
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>s>>a;
		if(s=="ATK") joff.pb(a);
		else jdef.pb(a);
	}
	sort(joff.rbegin(), joff.rend());
	sort(jdef.rbegin(), jdef.rend());
	FOR(i, 1, m){
		cin>>a;
		moje.insert(a);
	}
	moje2=moje;
	przebijdefa();
	cout<<max(przebijofa(), tylkofa())<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}