#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;
const int MAXC = 1005;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i=0; i<n; i++) putchar(i%k + 'a');
		puts("");
	}
}