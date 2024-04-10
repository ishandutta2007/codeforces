#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

const int N = 400005;
const int SQN = 405;

struct tree{
	int depth[N];
	int par[N];
	int mx[N];
	int nxt[N];
	int W[N];
	int len[N];
	ll sm[N];
	int curr;
	tree(){
		memset(depth, 0, sizeof depth);
		depth[1] = 1;
		len[1] = 1;
		curr = 1;
	}
	void add(int a, int w){
		curr++;
		// cerr << "adding " << curr << " to " << a << endl;
		par[curr] = a;
		W[curr] = w;
		depth[curr] = depth[a] + 1;
		if(depth[curr] % SQN == 1){
			mx[curr] = sm[curr] = w;
			nxt[curr] = a;
			len[curr] = 1;
		}
		else{
			mx[curr] = max(mx[a], w);
			sm[curr] = sm[a] + w;
			nxt[curr] = nxt[a];
			len[curr] = len[a] + 1;
		}
		// cerr << sm[curr] << " " << mx[curr] << " " << nxt[curr] << " " << len[curr] << endl;
	}

	int query1(int st){
		int a = W[st];
		st = par[st];
		while(st && mx[st] < a){
			st = nxt[st];
		}
		while(st && W[st] < a) st = par[st];
		return st;
	}

	int query2(int st, ll x){
		int ans = 0;
		ll currsm = 0;
		// cerr << "query " << st << endl;
		// trace(sm[st], len[st]);
		while(st && currsm + sm[st] <= x) currsm += sm[st], ans += len[st], st = nxt[st];
		// cerr << "st = " << st << endl;
		while(st && currsm + W[st] <= x) currsm += W[st], st = par[st], ans++;
		return ans;
	}
} T1, T2;

void add(int r, int w){
	T1.add(r, w);
	int ind = T1.query1(T1.curr);
	T2.add(ind, w);
}

int query(int r, ll x){
	return T2.query2(r, x);
}

int main(){
	int q;
	sd(q);
	int ans = 0;
	while(q--){
		int type;
		ll p, q;
		scanf("%d %lld %lld", &type, &p, &q);
		ll R = p ^ ans;
		ll x = q ^ ans;
		if(type == 1) add(R, x);
		else printf("%d\n", ans = query(R, x));
	}
}