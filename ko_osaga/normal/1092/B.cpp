#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;
const int MAXC = 1005;

int n, a[MAXN];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a + n);
	int ret = 0;
	for(int i=1; i<n; i+=2) ret += a[i] - a[i-1];
	cout << ret << endl;
}