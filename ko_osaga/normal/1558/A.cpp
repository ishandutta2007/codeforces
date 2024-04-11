#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 105;
const int mod = 998244353;

void solve(){
	int a, b;
	scanf("%d %d",&a,&b);
	int n = a + b;
	vector<int> v;
	for(int it = 0; it < 2; it++){
		for(int i = 0; i <= (n+1)/2 && i <= a; i++){
			int AH = i;
			int BB = a - i;
			int BH = n/2 - BB;
			int AB = (n+1)/2 - AH;
			if(BH >= 0 && AB >= 0) v.push_back(BB + AB);
		}
		swap(a, b);
	}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	printf("%d\n", sz(v));
	for(auto &i : v) printf("%d ", i);
	puts("");
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		solve();
	}
}