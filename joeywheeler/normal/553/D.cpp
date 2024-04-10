#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define EPS 1e-12

using namespace std;

int d[100005],h[100005],n,m,k;
vector<int> u[100005],b,t;

bool f(long double r) {
	 FO(i,1,n+1) d[i] = sz(u[i]), h[i] = ceil(r*d[i]-EPS);
	 queue<int> s;
	 for (int x : b) s.push(x), d[x] = 1e9;
	 while (!s.empty()) {
		  for (int x : u[s.front()]) if (--d[x] < h[x]) s.push(x), d[x] = 1e9;
		  s.pop();
	 }
	 t.clear();
	 FO(i,1,n+1) if (d[i] < 1e8) t.push_back(i);
	 return sz(t);
}

int main() {
	 scanf("%d%d%d", &n, &m, &k);
	 b.resize(k); for (int &x : b) scanf("%d", &x);
	 FO(i,0,m) {
		  int x,y; scanf("%d%d", &x, &y);
		  u[x].push_back(y);
		  u[y].push_back(x);
	 }
	 long double s = 0, e = 1, m;
	 while (e-s > EPS) (f(m=(s+e)/2)?s:e)=m;
	 f(s-EPS);
	 printf("%d\n", sz(t));
	 FO(i,0,sz(t)) printf("%d%c", t[i], " \n"[i+1==sz(t)]);
}