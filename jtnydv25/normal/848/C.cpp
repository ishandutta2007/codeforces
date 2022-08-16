#include <bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10, M = 2.2e7 + 10, offset = N;
int cnt = 0;
struct BIT{
    unsigned int bit[N];
    ll total;
    void update(int x, int y){
    	total += y;
    	x++;
    	for(; x < N; x += (x & (-x))){
    		bit[x] += y;
    	}
    }
	ll get(int x){
		if(x == 0) return total;
		ll ret = 0;
		for(; x; x -= (x & (-x))) ret += bit[x];
		return total - ret;
	}
};
const int K = 2000;
BIT T[100];
int pre[100005], nxt[100005], A[100005], lst[100005];
set<int> pos[100005];
pii curr[100005];
int n, m; 
void update(int i, const pii & x){
	int ind = i / K;
	T[ind].update(curr[i].F, -curr[i].S);
	T[ind].update(x.F, x.S);
}
ll get(int l, int r){
	int L = l;
	ll ret = 0;
	if(r - l <= 3 * K){
		for(int i =l; i <= r; i++) if(pre[i] >= L) ret += i - pre[i];
		return ret;
	}
	while(l % K){
		if(pre[l] >= L) ret += l - pre[l];
		l++;
	}
	while(r % K != K - 1){
		if(pre[r] >= L) ret += r - pre[r];
		r--;
	}
	int st = l/K, en = r / K;
	for(int i = st; i <= en; i++) ret += T[i].get(L);
	return ret;
}

void update(int i, int x){
	int y = A[i];
	if(A[i] == x) return;
	int p = pre[i], NXT = nxt[i];
	if(NXT <= n) pre[NXT] = p;
	if(p) nxt[p] = NXT;
	if(NXT <= n) update(NXT, {p, NXT - p});
	curr[NXT] = {pre[NXT], NXT - pre[NXT]};
	auto it1 = pos[x].upper_bound(i);
	nxt[i] = *it1;
	if(*it1 <= n){
		pre[*it1] = i;
		update(*it1, {i, *it1 - i});
		curr[*it1] = {i, *it1 - i};
	}
	it1--;
	pre[i] = *it1;
	update(i, {pre[i], i - pre[i]});
	nxt[pre[i]] = i;
	A[i] = x;
	curr[i] = {pre[i], i - pre[i]};
	pos[y].erase(i);
	pos[x].insert(i);
}

int main(){
	sd(n); sd(m);	
	nxt[0] = n + 1;
	for(int i = 1; i <= n; i++){
		nxt[i] = n + 1;
		pos[i] = {0, n + 1};
		sd(A[i]);
		pre[i] = lst[A[i]];
		update(i, {lst[A[i]], i - pre[i]});
		curr[i] = {pre[i], i - pre[i]};
		if(lst[A[i]]) nxt[lst[A[i]]] = i;
		lst[A[i]] = i;
	}
	for(int i = 1; i <= n; i++) pos[A[i]].insert(i);
	for(int i = 1; i <= m; i++){
		int t, l, r;
		sd(t); sd(l); sd(r);
		if(t == 1) update(l, r);
		else{
			printf("%u\n", get(l, r));
		}
	}
}