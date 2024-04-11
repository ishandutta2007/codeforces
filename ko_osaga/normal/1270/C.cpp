#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
const int MAXN = 2505;
using pi = pair<int, int>;
using lint = long long;

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		lint sum = 0;
		lint xors = 0;
		for(int i=0; i<n; i++){
			int x; scanf("%d",&x);
			sum += x;
			xors ^= x;
		}
		printf("2\n%lld %lld\n", xors, sum + xors);
	}
}