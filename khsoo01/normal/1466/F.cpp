#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int mod = 1e9+7, N = 500005;

int n, m, par[N], val = 1;
bool col[N];
pii a[N];
vector<pii> adj[N];
vector<int> ans;

int Find (int X) {
	if(par[X] == X) return X;
	return par[X] = Find(par[X]);
}

bool Union (int A, int B) {
	A = Find(A);
	B = Find(B);
	if((col[A] && col[B]) || A == B) return false;
	if(col[A]) swap(A, B);
	par[A] = B;
	return true;
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) {
		int T;
		scanf("%d%d",&T,&a[i].X);
		if(T == 2) scanf("%d",&a[i].Y);
	}
	iota(par+1, par+1+n, 1);
	for(int i=1;i<=m;i++) {
		int A, B;
		tie(A, B) = a[i];
		if(B) {
			if(Union(A, B)) {
				ans.push_back(i);
				val = val * 2 % mod;
			}
		}
		else {
			A = Find(A);
			if(!col[A]) {
				col[A] = true;
				ans.push_back(i);
				val = val * 2 % mod;
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d %d\n", val, (int)ans.size());
	for(auto &T : ans) {
		printf("%d ", T);
	}
	puts("");
}