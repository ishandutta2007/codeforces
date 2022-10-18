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

int t[110];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, odp=inf, lodp;
	cin>>n;
	FOR(i, 1, n){
		cin>>t[i];
	}
	FOR(x, 1, n){
		lodp=0;
		FOR(j, 1, n){
			lodp+=t[j]*(abs(x-j)+abs(j-1)+abs(1-x));
		}
		odp=min(odp, lodp);
	}
	cout<<2*odp<<ent;
	return 0;
}