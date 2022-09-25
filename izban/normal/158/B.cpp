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

const int maxn=100100;

int n,a[maxn],b[10],ans;
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	ans+=min(b[3],b[1]);
	b[3]-=ans;
	b[1]-=ans;
	ans+=b[3];
	ans+=b[4];
	ans+=b[2]/2;
	b[2]&=1;
	ans+=b[1]/4;
	b[1]%=4;
	int k=b[1]+2*b[2];
	if (k && k<=4) ans++;
	if (k>4) ans+=2;
	cout << ans;
	return 0;
}