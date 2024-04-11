#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;
using lint = long long;

int n;
int l[MAXN], r[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&l[i]);
	}
	lint res = 0, ret = 0;
	for(int i=0; i<n; i++){
		lint cur = l[i];
		lint upd = min(cur / 2, res);
		cur -= upd * 2;
		res -= upd;
		ret += upd;
		upd = cur / 3;
		cur -= upd * 3;
		ret += upd;
		res += cur;
	}
	cout << ret << endl;
}