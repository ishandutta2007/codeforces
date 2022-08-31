#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

struct dsu{
	int n;
	vector<int> par;
	vector<int> wt;
	vector<int> num, sz;
	int minSum;
	dsu(int n) : n(n), par(n), wt(n), num(n), sz(n){
		iota(all(par), 0);
		fill(all(sz), 1);
		minSum = 0;
	}

	pii root(int x){
		int px = par[x];
		int wx = wt[x];
		if(px == x){
			return {x, wx};
		}
		pii z = root(px);
		par[x] = z.F;
		wt[x] = z.S ^ wx;
		return {par[x], wt[x]};
	}

	int getWeight(int root){
		if(root == 0) return num[root];
		return min(num[root], sz[root] - num[root]);
	}

	void merge(int x, int y, int z){
		pii rx = root(x), ry = root(y);
		x = rx.F, y = ry.F;
		int wx = rx.S, wy = ry.S;
		if(x == y) return;
		if(x > y){
			swap(x, y);
			swap(wx, wy);
		}
		int y_new = wx ^ wy ^ z;
		minSum -= (getWeight(x) + getWeight(y));
		par[y] = x;
		wt[y] = y_new;
		sz[x] += sz[y];
		num[x] += y_new ? sz[y] - num[y] : num[y];
		minSum += getWeight(x);
	}
};

const int N = 300005;
vector<int> pos[N];
char s[N];
int main(){
	int n, k; sd(n); sd(k);
	scanf("%s", s + 1);
	for(int i = 1; i <= k; i++){
		int c; sd(c);
		for(int j = 1; j <= c; j++){
			int x; sd(x);
			pos[x].push_back(i);
		}
	}

	dsu D(k + 1);

	for(int i = 1; i <= n; i++){
		int szpos = pos[i].size();
		if(szpos == 1){
			D.merge(0, pos[i][0], s[i] == '0');
		} else if(szpos == 2){
			D.merge(pos[i][0], pos[i][1], s[i] == '0');
		}
		printf("%d\n", D.minSum);
	}
}