#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back
const int N = 1005;

string A[N];

int main(){
	int i, j, k, n, m, t;
	cin >> n;
	for(i = 1; i <= n; i++) cin >> A[i];
		int ans = 0;
	for(int i = 0; i < 7; i++){
		int cnt =0;
		for(int j = 1; j <= n; j++)
			if(A[j][i] == '1') cnt++;
		ans = max(ans, cnt);
	}
	cout << ans;
}