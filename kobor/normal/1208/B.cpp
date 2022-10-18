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

const int N=2020;

int t[N];
int n;
set<int> syfy;
map<int, int> cnt;

void dodaj(int val){
	cnt[val]++;
	if(cnt[val]==2) syfy.insert(val);
}

void usun(int val){
	cnt[val]--;
	if(cnt[val]==1) syfy.erase(val);
}

void reset(){
	cnt.clear();
	FOR(i, 1, n) dodaj(t[i]);
}

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(dl, 0, n-2){
		reset();
		FOR(i, 1, dl) usun(t[i]);
		if(!SIZE(syfy)){
			cout<<dl<<ent;
			return;
		}
		FOR(i, dl+1, n){
			dodaj(t[i-dl]);
			usun(t[i]);
			if(!SIZE(syfy)){
				cout<<dl<<ent;
				return;
			}
		}
	}
	cout<<n-1<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}