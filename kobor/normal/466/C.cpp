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

const int N=5e5+5;

int pref[N];
int t[N];
ll sum, aktsum, ans;
int n;

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) sum+=t[i];
	if(sum%3){
		cout<<0<<ent;
		return;
	}
	sum/=3;
	FORD(i, n, 1){
		aktsum+=t[i];
		if(aktsum==sum) pref[i-1]++;
	}
	FORD(i, n+1, 1) pref[i]+=pref[i+1];
	aktsum=0;
	FOR(i, 1, n){
		aktsum+=t[i];
		if(aktsum==sum) ans+=pref[i+1];
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}