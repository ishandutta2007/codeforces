#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int n, a[MAXN], b[MAXN];
set<int> s[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b, b+n);
	for(int i=0; i<n; i++) s[a[i]].insert(i);
	int cpnt = 0, sz = n;
	lint ret = n;
	for(int i=0; i<n; i++){
		auto l = s[b[i]].lower_bound(cpnt);
		if(l == s[b[i]].end()){
			ret += sz;
			cpnt = 0;
			l = s[b[i]].lower_bound(cpnt);
		}
		cpnt = *l;
		s[b[i]].erase(l);
		sz--;
	}
	cout << ret;
}