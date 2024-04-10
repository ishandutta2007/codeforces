#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define INF 1000000000007
#define Pi 3.141592653589793238462643383279502884
typedef pair<long long, long long> pairll;
long double n,r,c;
int main() {

	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	cin>>n>>r;
	c = 2/(2*sin(Pi/n))-1;
	cout<<fixed<<setprecision(7)<<r/c;
}