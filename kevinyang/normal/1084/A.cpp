#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e2 + 2;
int n, ans = INT_MAX, arr[mn];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int e = 1; e <= n; e++){
		int cnt = 0;
		for(int i = 1, alt; i <= n; i++){
			alt = 2 * (abs(e - i) + abs(i - 1) + abs(e - 1));
			cnt += arr[i] * alt;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}