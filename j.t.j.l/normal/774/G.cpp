#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	ll a, h, w;
	cin>>a>>h>>w;
	ll p, q, r;
	p = abs(h - w);
	q = h + a;
	r = __gcd(p, q);
	ll c = a;
	if (r < c || h < a || w < a) cout<<-1<<endl;
	else{
		ll u = r / c;
		printf("%.16lf\n", r * 1.0 / u - c);
	}
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}