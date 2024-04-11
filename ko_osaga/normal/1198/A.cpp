#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, lint>;
const int MAXN = 600000;
const int mod = 1e9 + 7;
#define has(msk, v) (((msk) >> (v)) & 1)

map<int, int> mp;
int a[MAXN];

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	m *= 8;
	m /= n;
	int ans = 1e9;
	if(m <= 30) ans = (1 << m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a + n);
	int e = 0;
	int ret = 0;
	for(int i=0; i<n; i++){
		mp[a[i]]++;
		while(mp.size() > ans){
			mp[a[e]]--;
			if(mp[a[e]] == 0) mp.erase(a[e]);
			e++;
		}
		ret = max(ret, i + 1 - e);
	}
	cout << n - ret << endl;
}