//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VPII;

const LD EPS=10e-9;
const int MOD=1000000007;
const int PMOD1=606574021;
const int PMOD2=606574027;
const int INF=1000000009;
const LL LLINF=1000000000000000009;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define MP make_pair
#define ST first
#define ND second

//END OF TEMPLATE

LL t[200000];
LL z[200000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	LL w, l, kon=0;
	cin>>w>>l;
	//w--;
	FOR(i, 1, w-1){
		cin>>t[i];
	}
	z[0]=INF;
	t[w]=INF;
	FOR(i, 1, w){
		while(kon+l<i){
			kon++;
		}
		while(t[i]>z[kon]){
			//cout<<"SKacze z: "<<kon<<" na "<<i<<" zab "<<z[kon]<<'\n';
			z[i]+=z[kon];
			t[i]-=z[kon];
			kon++;
			if(kon==i){
				break;
			}
		}
		if(kon==i)
			continue;
		//cout<<"SSSKacze z: "<<kon<<" na "<<i<<" zab "<<t[i]<<'\n';
		z[i]+=t[i];
		z[kon]-=t[i];
	}
	cout<<z[w]<<'\n';
	return 0;
}