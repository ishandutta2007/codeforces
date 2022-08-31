#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n, m, k, s, e;
pi a[MAXN];

void solve(){
	int n = rand() % 20 + 1;
	cout << n << endl;
	vector<int> arr(n);
	set<int> s;
	while(sz(s) < n){
		s.insert(rand() % (2*n) + 1);
	}
	for(auto &i : arr){
		i = *s.begin();
		s.erase(i);
	}
	vector<int> b = arr;
	while(true){
		vector<int> v;
		for(int j=1; j<n; j++){
			if(b[j-1] + 2 <= b[j]){
				v.push_back(j);
			}
		}
		if(sz(v) == 0) break;
		for(auto &j : v){
			b[j-1]++;
			b[j]--;
		}
	}
	for(auto &i : arr) printf("%d ", i);
	puts("");
	for(auto &i : b) printf("%d ", i);
	puts("");
	assert(b.back() - b[0] >= sz(b) - 2);
}
int main(){
	int n; scanf("%d",&n);
	vector<lint> v(n);
	for(auto &i : v) scanf("%lld",&i);
	lint sum = accumulate(all(v), 0ll);
	sum -= 1ll * n * (n-1)/2;
	sum /= n;
	vector<lint> w(n);
	for(int i=0; i<n; i++) w[i] = sum + i;
	lint kappa = accumulate(all(v), 0ll) - accumulate(all(w), 0ll);
	assert(kappa >= 0 && kappa <= n);
	for(int i=0; i<kappa; i++) w[i]++;
	for(auto &i : w) printf("%lld ", i);
}