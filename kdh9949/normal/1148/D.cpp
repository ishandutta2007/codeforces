#include <bits/stdc++.h>
using namespace std;

struct A{ int a, b, i; };

int n;
vector<A> v, w;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x, y; scanf("%d%d", &x, &y);
		if(x < y) v.push_back({x, y, i});
		else w.push_back({x, y, i});
	}
	sort(v.begin(), v.end(), [](A p, A q){ return p.a > q.a; });
	sort(w.begin(), w.end(), [](A p, A q){ return p.a < q.a; });
	if(v.size() < w.size()) v = w;
	printf("%d\n", v.size());
	for(A i : v) printf("%d ", i.i);
	puts("");
}