#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, m, a[MAXN], b[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<m; i++) scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	if(a[n-1] > b[0]){
		puts("-1");
		return 0;
	}
	lint ret = 1ll * m *accumulate(a, a + n, 0ll);
	vector<int> v;
	for(int i=0; i<m; i++){
		if(a[n-1] < b[i]){
			v.push_back(b[i]);
		}
	}
	if(v.size() > 1ll * n * (m - 1)){
		puts("-1");
		return 0;
	}
	int ptr = 0;
	for(int i=0; i<v.size(); i++){
		ret += v[i] - a[n - 1 - ptr / (m - 1)];
		ptr++;
	}
	cout << ret << endl;
}