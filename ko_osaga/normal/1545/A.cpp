#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 500005;
const int MAXT = 1050000;

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		for(int i = x; i < MAXN; i+=i&-i) tree[i] += v;
	}
	int query(int x){
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += tree[i];
		return ret;
	}
}bit;

int main(){
	int t; scanf("%d",&t);
	for(int i = 0; i < t; i++){
		int n; scanf("%d",&n);
		vector<int> a(n);
		for(int j = 0; j < n; j++) scanf("%d",&a[j]);
		for(int j = 0; j < 2; j++){
			vector<int> w;
			for(int k = j; k < n; k += 2) w.push_back(a[k]);
			sort(all(w));
			for(int k = j; k < n; k += 2) a[k] = w[(k - j) / 2];
		}
		puts(is_sorted(all(a)) ? "YES" : "NO");
	}
}