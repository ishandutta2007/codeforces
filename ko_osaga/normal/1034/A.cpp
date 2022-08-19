#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MAXN = 300005;

int gcd(int x, int y){ return y ? gcd(y, x%y) : x; }

int cnt[15000005];
bool che[15000005];

int n, a[MAXN];

int main(){
	scanf("%d",&n);
	int gg = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		gg = gcd(gg, a[i]);
	}
	for(int i=1; i<=n; i++){
		a[i] /= gg;
		cnt[a[i]]++;
	}
	int dap = 1e9;
	for(int i=2; i<=15000000; i++){
		if(che[i]) continue;
		int tmp = 0;
		for(int j=i; j<=15000000; j+=i){
			che[j] = 1;
			tmp += cnt[j];
		}
		if(tmp != n) dap = min(dap, n - tmp);
	}
	if(dap >= n) dap = -1;
	cout << dap << endl;
}