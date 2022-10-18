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

const int N=1e6+5;
const int M=1<<20;

unordered_map<int, int> MA;
int t[N], pref[N], suf[N], tre[2*M+5];
int n;
ll ans;

void add(int l, int val){
	l+=M;
	while(l){
		tre[l]+=val;
		l>>=1;
	}
}

int query(int l, int r){
	int ret=0;
	l+=M; r+=M;
	while(l<=r){
		if(l&1) ret+=tre[l++];
		if(!(r&1)) ret+=tre[r--];
		l>>=1; r>>=1;
	}
	return ret;
}

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) pref[i]=++MA[t[i]];
	FOR(i, 1, n) suf[i]=MA[t[i]]--;
	FOR(i, 1, n) add(suf[i], 1);
	FOR(i, 1, n){
		add(suf[i], -1);
		ans+=query(1, pref[i]-1);
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}