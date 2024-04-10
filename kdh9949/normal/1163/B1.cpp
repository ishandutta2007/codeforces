#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

using pii = pair<int, int>;
#define x first
#define y second

int n, c[N], r = 1;
set<pii> ss;

int main(){
	scanf("%d", &n);
	for(int i = 1, x; i <= n; i++){
		scanf("%d", &x);
		ss.erase(pii(c[x], x));
		ss.insert(pii(++c[x], x));
		if(ss.size() == 1){ if(i < n) r = i + 1; continue; }
		int mn = ss.begin()->x;
		int mx = ss.rbegin()->x;
		if(mn == mx && i < n) r = i + 1;
		else if(mn + 1 == mx && mn * ss.size() + 1 == i) r = i;
		else if(mn == 1 && mx * (ss.size() - 1) + 1 == i) r = i;
	}
	printf("%d\n", r);
}