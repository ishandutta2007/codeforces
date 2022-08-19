#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
using lint = long long;
using pi = pair<lint, lint>;

int n;
int sum[MAXN];
char str[MAXN];
int main(){
	cin >> n >> (str + 1);
	if(count(str + 1, str + n + 1, 'G') == n){
		cout << n << endl;
		return 0;
	}
	for(int i=1; i<=n; i++){
		sum[i] = sum[i-1] + (str[i] == 'S');
	}
	int ptr = 0;
	int ret = 0;
	for(int i=1; i<=n; i++){
		while(ptr < n && sum[ptr+1] - sum[i-1] <= 1) ptr++;
		ret = max(ret, ptr - i + 1);
	}
	ret = min(ret, (int)count(str + 1, str + n + 1, 'G'));
	cout << ret << endl;
}