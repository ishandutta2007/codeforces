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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

int t[200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, dinsmax=0, dinsak, ile=0;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>a;
		if(!t[a]){
			ile++;
		}
		t[a]++;
	}
	FOR(i, 1, 100){
		dinsak=t[i]/m;
		if(t[i]%m){
			dinsak++;
		}
		dinsmax=max(dinsmax, dinsak);
	}
	cout<<m*dinsmax*ile-n<<ent;
	return 0;
}