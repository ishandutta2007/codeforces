#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=200010;
const double pi=3.1415926535897932;
const double eps=1e-10;

int n,m,k,p,ans;
string s,s1,s2;
double R,r;
int a[maxn],b[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> R >> r;
	double a=2*pi/n;
	if (n==1 && r<=R) cout << "YES"; else 
	if (4*sqr(r)-2*sqr(R-r)+2*sqr(R-r)*cos(a)<eps) cout << "YES";
	else cout << "NO";
	return 0;
}