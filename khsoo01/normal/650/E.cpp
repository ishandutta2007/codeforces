#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 500005;

int n, p[N], pa[N], pb[N], ea[N], eb[N];
pii a[N], b[N];

vector<pii> aa[N], ab[N], ans;
map<pii,bool> mp;

int Find (int X) {
	if(p[X] == X) return X;
	return p[X] = Find(p[X]);
}

void Union (int A, int B) {
	A = Find(A);
	B = Find(B);
	p[max(A, B)] = min(A, B);
}

void calc1 (int C, int P) {
	for(auto &T : ab[C]) {
		int A, B;
		tie(A, B) = T;
		if(A == P) continue;
		pb[A] = C;
		eb[A] = B;
		calc1(A, C);
	}
}

void calc2 (int C, int P) {
	for(auto &T : aa[C]) {
		int A, B;
		tie(A, B) = T;
		if(A == P) continue;
		pa[A] = C;
		ea[A] = B;
		calc2(A, C);
	}
	if(P) ans.push_back({ea[C], eb[C]});
}

int main()
{
	scanf("%d",&n);
	iota(p+1, p+1+n, 1);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a[i].X,&a[i].Y);
		if(a[i].X > a[i].Y) swap(a[i].X, a[i].Y);
		mp[a[i]] = true;
	}
	for(int i=1;i<n;i++) {
		scanf("%d%d",&b[i].X,&b[i].Y);
		if(b[i].X > b[i].Y) swap(b[i].X, b[i].Y);
		if(mp[b[i]]) Union(b[i].X, b[i].Y);
	}
	for(int i=1;i<n;i++) {
		int A = Find(a[i].X), B = Find(a[i].Y);
		if(A != B) {
			aa[A].push_back({B, i});
			aa[B].push_back({A, i});
		}
		A = Find(b[i].X), B = Find(b[i].Y);
		if(A != B) {
			ab[A].push_back({B, i});
			ab[B].push_back({A, i});
		}
	}
	calc1(1, 0);
	calc2(1, 0);
	printf("%d\n",(int)ans.size());
	for(auto &T : ans) {
		int A, B;
		tie(A, B) = T;
		printf("%d %d %d %d\n", a[A].X, a[A].Y, b[B].X, b[B].Y);
	}
}