#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 300005;

int n;
pi a[MAXN];
vector<int> l, r;
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		if(a[i].first < a[i].second) l.push_back(i);
		else r.push_back(i);
	}
	sort(l.begin(), l.end(), [&](const int &x, const int &y){
		return a[x].first > a[y].first;
	});
	sort(r.begin(), r.end(), [&](const int &x, const int &y){
		return a[x].second < a[y].second;
	});
	if(l.size() < r.size()) swap(l, r);
		cout << l.size() << endl;
		for(auto &i : l) printf("%d ", i + 1);
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