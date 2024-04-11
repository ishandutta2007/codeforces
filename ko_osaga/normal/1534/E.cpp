#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3000005;
const int mod = 1e9 + 7;

int d[505], par[505];

int main(){
	int n, k;
	cin >> n >> k;
	memset(d, 0x3f, sizeof(d));
	queue<int> que;
	auto enque = [&](int x, int v, int p){
		if(d[x] > v){
			d[x] = v;
			par[x] = p;
			que.push(x);
		}
	};
	enque(0, 0, 0);
	while(sz(que)){
		int x = que.front(); que.pop();
		for(int a = 0; a <= k; a++){
			int b = k - a;
			if(a <= x && b <= n - x){
				enque(x + b - a, d[x] + 1, x);
			}
		}
	}
	if(d[n] > 1e7){
		puts("-1");
		return 0;
	}
	vector<int> v;
	for(int i = n; i; i = par[i]){
		v.push_back(i);
	}
	v.push_back(0);
	reverse(all(v));
	int ret = 0;
	vector<int> chk(n);
	for(int i = 1; i <= d[n]; i++){
		int L = v[i - 1], R = v[i];
		int q0 = -1, q1 = -1;
		for(int a = 0; a <= k; a++){
			if(L + (k - a) - a == R){
				q0 = a;
				q1 = k - a;
			}
		}
		assert(~q0);
		vector<int> v;
		for(int i = 0; i < n; i++){
			if(q0 && chk[i]){
				chk[i] = 0;
				v.push_back(i);
				q0--;
			}
			else if(q1 && !chk[i]){
				chk[i] = 1;
				v.push_back(i);
				q1--;
			}
		}
		printf("?");
		for(auto &i : v) printf(" %d", i+1);
		printf("\n"); fflush(stdout);
		int x; cin >> x; ret ^= x;
	}
	cout << "! " << ret << endl;
	return 0;
}