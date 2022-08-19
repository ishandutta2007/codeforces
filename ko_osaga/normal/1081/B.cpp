#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 998244353;

int n, a[MAXN], dap[MAXN], num;
vector<int> v[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		a[i] = n - a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1; i<=n; i++){
		if(v[i].size() % i){
			puts("Impossible");
			return 0;
		}
		for(int j=0; j<v[i].size(); j+=i){
			num++;
			for(int k=0; k<i; k++){
				dap[v[i][j+k]] = num;
			}
		}
	}
	puts("Possible");
	for(int i=0; i<n; i++) printf("%d ", dap[i]);
}