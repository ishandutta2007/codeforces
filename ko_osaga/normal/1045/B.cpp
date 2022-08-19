#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;
const int MAXN = 400005;
const int mod = 1e9 + 7;

int n, m, a[MAXN];
int d[MAXN], e[MAXN];
int fail[MAXN];

void report(vector<int> &ans){
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(auto &i : ans) printf("%d ", i);
	exit(0);
}

int main(){
	vector<int> ans;
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	if(n == 1){
		cout << 1 << endl;
		cout << 2 * a[0] % m << endl;
		return 0;
	}
	for(int i=0; i<n; i++) a[i + n] = a[i] + m;
	for(int i=0; i<n-1; i++) d[i] = a[i+1] - a[i];
	for(int i=0; i<2*n-2; i++) e[i] = a[i+1] - a[i];
	reverse(e, e + 2*n-2);
	int p = 0;
	for(int i=1; i<n-1; i++){
		while(p && d[i] != d[p]) p = fail[p];
		if(d[i] == d[p]) p++;
		fail[i + 1] = p;
	}
	p = 0;
	for(int i=0; i<2*n-2; i++){
		while(p && e[i] != d[p]) p = fail[p];
		if(e[i] == d[p]) p++;
		if(p == n - 1){
			int M = 10*n - 4 - i;
			M %= n;
			ans.push_back((a[0] + a[M]) % m);
			p = fail[p];
		}
	}
	report(ans);
}