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

ll n, m, k, a, maks1, maks2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	maks1=maks2=-inf;
	FOR(i, 1, n){
		cin>>a;
		if(a>=maks1){
			maks2=maks1;
			maks1=a;
		}
		else if(a>maks2){
			maks2=a;
		}
	}
	cout<<m/(k+1)*(k*maks1+maks2)+(m%(k+1))*maks1<<ent;
	return 0;
}