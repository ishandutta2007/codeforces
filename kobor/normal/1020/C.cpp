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

const int N=3010;

int n, m;
vi vote[N];

ll cost(int num){
	ll ret=0;
	int akvotes=SIZE(vote[1]);
	vi rem;
	FOR(i, 2, n){
		FOR(j, 0, SIZE(vote[i])-num){
			ret+=vote[i][j];
			akvotes++;
		}
		FOR(j, max(0, SIZE(vote[i])-num+1), SIZE(vote[i])-1){
			rem.pb(vote[i][j]);
		}
	}
	sort(rem.begin(), rem.end());
	if(num-akvotes>SIZE(rem)) return INF;
	FOR(i, 0, num-akvotes-1) ret+=rem[i];
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	ll ans=INF;
	cin>>m>>n;
	FOR(i, 1, m){
		cin>>a>>b;
		vote[a].pb(b);
	}
	FOR(i, 1, n) sort(vote[i].begin(), vote[i].end());
	FOR(i, 1, m) ans=min(ans, cost(i));
	cout<<ans<<ent;
	return 0;
}