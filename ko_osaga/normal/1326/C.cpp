#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int MAXM = 200005;
const int mod = 998244353;

int n, k;

int main(){
	scanf("%d %d",&n,&k);
	vector<int> v;

	lint tmp = 0;
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		if(x >= n - k + 1) v.push_back(i), tmp += x;
	}
	cout << tmp << " ";
	lint ret = 1;
	for(int i=1; i<sz(v); i++) ret = ret * (v[i] - v[i-1]) % mod;
	cout << ret << endl;
}