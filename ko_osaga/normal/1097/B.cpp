#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100000;
bitset<MAXN> bs;

int main(){
	int n; cin >> n;
	bs[0] = 1;
	while(n--){
		int x; cin >> x;
		bs = (bs << x) | (bs << (360 - x));
	}
	for(int i=0; i<MAXN; i+=360){
		if(bs[i]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}