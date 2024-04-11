#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 2005;

bool isprime(int x){
	for(int i = 2; i * i <= x; i++){
		if(x% i == 0) return 0;
	}
	return 1;
}

int main(){
	int tc; cin >> tc;
	for(int i = 1; i <= tc; i++){
		int n; cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		int sum = accumulate(all(a), 0);
		if(isprime(sum)){
			for(int i = 0; i < n; i++){
				if(isprime(sum - a[i])) continue;
				printf("%d\n", n - 1);
				for(int j = 0; j < n; j++) {
					if(j != i) printf("%d ", j + 1);
				}
				break;
			}
		} else{
				printf("%d\n", n);
				for(int j = 0; j < n; j++) {
					printf("%d ", j + 1);
				}
		}
		puts("");
	}
}