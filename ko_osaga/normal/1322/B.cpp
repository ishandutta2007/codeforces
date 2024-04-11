#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 1000005;

int n, a[MAXN], b[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	int ret = 0;
	for(int i=0; i<25; i++){
		for(int j=0; j<n; j++){
			b[j] = a[j] % (2 << i);
		}
		sort(b, b + n);
		lint par = 0;
		vector<int> l, r;
		for(int j=0; j<n; j++){
			auto p1 = lower_bound(b, b + n, (1<<i) - b[j]);
			auto p2 = lower_bound(b, b + n, 2*(1<<i) - b[j]);
			auto p3 = lower_bound(b, b + n, 3*(1<<i) - b[j]);
			auto p4 = lower_bound(b, b + n, 4*(1<<i) - b[j]);
			par += (p2 - p1);
			par += (p4 - p3);
			if(((2 * b[j]) >> i) & 1) par -= 1;
		}
		assert(par % 2 == 0);
		par /= 2;
		if(par & 1) ret += (1 << i);
	}
	cout << ret << endl;
}