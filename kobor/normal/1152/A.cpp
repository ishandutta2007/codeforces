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

int par[2], par2[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>a;
		par[a%2]++;
	}
	FOR(i, 1, m){
		cin>>a;
		par2[a%2]++;
	}
	cout<<min(par[0], par2[1])+min(par[1], par2[0])<<ent;
	return 0;
}