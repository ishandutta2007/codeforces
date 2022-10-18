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

priority_queue<pair<long long, int> > Q;

long long t[200000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, nn=0;
	pair<long long, int> v;
	cin>>n;
	FOR(i, 0, n-1){
		cin>>t[i];
		Q.push(MP(t[i]*-1, -1*i));
	}
	while(!Q.empty()){
		v=Q.top();
		Q.pop();
		v.ND*=-1;
		if(!Q.empty()){
			if(v.ST==Q.top().ST){
				t[v.ND]=-1;
				v=Q.top();
				Q.pop();
				v.ND*=-1;
				t[v.ND]*=2;
				Q.push(MP(t[v.ND]*-1, v.ND*-1));
			}
		}
	}
	FOR(i, 0, n-1){
		if(t[i]!=-1){
			nn++;
		}
	}
	cout<<nn<<'\n';
	FOR(i, 0, n-1){
		if(t[i]!=-1){
			cout<<t[i]<<' ';
		}
	}
	cout<<'\n';
	return 0;
}