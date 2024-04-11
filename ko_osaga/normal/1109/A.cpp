#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 2000005;

int n, a[MAXN], cnt[2][MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		a[i] = a[i-1] ^ x;
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		cnt[(i-1)%2][a[i-1]]++;
		ret += cnt[i%2][a[i]];
	}
	cout << ret << endl;
}