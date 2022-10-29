#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int ans[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < 2 *n; i++)
		ans[i] = n;
	for(int i = 1; i < n; i++){
		int x;
		if (i & 1)
			x = i >> 1;
		else
			x = (n - 1) + (i >> 1);
		ans[x] = ans[x + (n - i)] = i;
	}
	for(int i = 0; i < 2 *n; i++)
		printf("%d%c", ans[i], " \n"[i == 2 * n - 1]) ;
	return 0;
}