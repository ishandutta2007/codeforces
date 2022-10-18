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

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define sp ' '
#define ent '\n'

//END OF TEMPLATE

pair<string, LL> t[100010];
LL s[100010];
LL h[100010];

bool comp(pair<string, LL> a, pair<string, LL> b){
	return h[b.nd]*s[a.nd]>h[a.nd]*s[b.nd];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	LL wyn=0;
	LL ile=0;
	string odp="";
	cin>>n;
	FOR(i, 0, n-1){
		cin>>t[i].st;
		t[i].nd=i;
	}
	FOR(i, 0, n-1){
		FOR(j, 0, SIZE(t[i].st)-1){
			if(t[i].st[j]=='s'){
				s[i]++;
			}
			else{
				h[i]++;
			}
		}
	}
	sort(t, t+n, comp);
	FOR(i, 0, n-1){
		odp+=t[i].st;
	}
	FOR(i, 0, SIZE(odp)-1){
		if(odp[i]=='s'){
			ile++;
		}
		else{
			wyn+=ile;
		}
	}
	cout<<wyn<<ent;
	return 0;
}