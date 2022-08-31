#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 300005;

int n;
pi a[MAXN], b[MAXN];
vector<tuple<int, int, int>> trace;

void Collide(int idx1, int idx2, int howmuch){
	trace.emplace_back(a[idx1].second, a[idx2].second, howmuch);
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i + 1;
	}
	for(int i=0; i<n; i++){
		scanf("%d",&b[i].first);
		b[i].second = i + 1;
	}
	sort(a, a+n);
	sort(b, b+n);
	vector<pi> stk;
	for(int i=0; i<n; i++){
		int dx = b[i].first - a[i].first;
		if(dx > 0){
			stk.emplace_back(dx, i);
		}
		else if(dx < 0){
			dx = -dx;
			while(!stk.empty() && dx > 0){
				auto x = stk.back();
				stk.pop_back();
				int delta = min(x.first, dx);
				Collide(x.second, i, delta);
				x.first -= delta;
				dx -= delta;
				if(x.first > 0) stk.push_back(x);
			}
			if(dx > 0){
				puts("NO");
				return 0;
			}
		}
	}
	if(stk.size()){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n", trace.size());
	for(auto &i : trace){
		int f1, f2, f3;
		tie(f1, f2, f3) = i;
		printf("%d %d %d\n", f1, f2, f3);
	}
}

/*
int n;
int a[MAXN];
int rev[MAXN];
vector<pi> seq;

int mode(int x){
	if(x == 1) return 1;
	if(x == n) return 2;
	if(x <= n / 2) return 2;
	return 1;
}

void Swap(int x, int y){
	if(x == y) return;
	swap(a[x], a[y]);
	swap(rev[a[x]], rev[a[y]]);
	seq.emplace_back(x, y);
}

vector<int> belong[3];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		rev[a[i]] = i;
		if(mode(i) != mode(a[i])) belong[mode(i)].push_back(i);
	}
	assert(belong[1].size() == belong[2].size());
	for(int i=0; i<belong[1].size(); i++){
		int w = belong[2][i];
		int x = belong[1][i];
		if(w != n) Swap(w, n);
		if(x != 1) Swap(x, 1);
		Swap(1, n);
	}
	for(int i=n/2+1; i<n; i++){
		if(a[i] == 1) Swap(i, 1);
	}
	for(int i=2; i<=n/2; i++){
		if(a[i] == n) Swap(n, i);
	}
	{
		for(int i=2; i<=n-1; i++){
			if(i != rev[i]){
				int pos = rev[i];
				if(rev[i] <= n / 2){
					Swap(pos, n);
					Swap(i, n);
					Swap(pos, n);
				}
				else{
					Swap(pos, 1);
					Swap(i, 1);
					Swap(pos, 1);
				}
			}
		}
	}
	assert(is_sorted(a, a + n + 1));
	printf("%d\n", seq.size());
	for(auto &i : seq) printf("%d %d\n", i.first, i.second);
}*/