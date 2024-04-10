#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n, m;
char s[MAXM];
int a[MAXM];
int f[MAXN][MAXN];

ll absll(ll x){
	return x < 0 ? -x : x;
}

ll a1,a2,a3,a4,a5,a6;

void read(){
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
}

ll calc(ll x, ll y){
	return 2 * x * y + y * y;
}

ll calc2(ll x, ll y, ll z){
	return (x + y) * 2 * z;
}

void solve(){
	assert(a2+a3 == a5+a6);
	ll tmp;
	assert((tmp = calc2(a1, min(a2, a6), absll(a2 - a6))) == calc2(a4, min(a3, a5), absll(a3 - a5)));
	cout<<calc(a1, min(a2, a6))+calc(a4, min(a3, a5))+tmp<<endl;
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}