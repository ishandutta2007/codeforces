#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int MAXM = 200005;

int n, b[MAXN], a[MAXN], x[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&b[i]); // b[i] = a[i] - x[i-1]
		a[i] = b[i] + x[i - 1];
		x[i] = max(x[i - 1], a[i]);
		printf("%d ", a[i]);
	}
}