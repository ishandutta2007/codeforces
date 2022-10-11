//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define R first
#define L second
#define r first
#define ind second

ll n, q, ans, a[maxn], dsu[maxn], Size[maxn], t[maxn], mx[maxn];
pll Un[maxn];
pll A[maxn];

bool check(pll se, pll fi){
	if(fi.R >= se.L && fi.R <= se.R || fi.L >= se.L && fi.L <= se.R || se.R >= fi.L && se.R <= fi.R || se.L >= fi.L && se.L <= fi.R){
		return 1;
	}
	return 0;
}
 
pll u(pll fi, pll se){
	pll p;
	p.L = min(fi.L, se.L);
	p.R = max(fi.R, se.R);
	return p;
}
 
void initialize(){
    for(ll i = 0; i < maxn; i++){
    	dsu[i] = i;
    	Size[i] = 1;
	}
}
 
ll root(ll i){
	if (dsu[i] == i){
		return dsu[i];
	}
	dsu[i] = root(dsu[i]);
	return dsu[i];
}
 
bool find(ll i, ll j){
	if (root(i) == root(j)){
		return 1;
	}
	return 0;
}
 
void Union(ll i, ll j){
	if (find(i, j)){
		return;
	}
    ll root_i = root(i);
    ll root_j = root(j);
    if(Size[root_i] < Size[root_j]){
		dsu[root_i] = dsu[root_j];
		Size[root_j] += Size[root_i];
		Un[root_j] = u(Un[root_j], Un[root_i]);
	}
	else{
		dsu[root_j] = dsu[root_i];
		Size[root_i] += Size[root_j];
		Un[root_i] = u(Un[root_j], Un[root_i]);
	}
}

void fix(ll i, ll j){
	ll ri = root(i), rj = root(j);
	if(check(Un[ri], Un[rj])){
		Union(ri, rj);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> q;
	
	for(ll i = 0; i < maxn; i++){
		Un[i].L = inf;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		t[a[i]]++;
		Un[a[i]].L = min(Un[a[i]].L, i);
		Un[a[i]].R = max(Un[a[i]].R, i);
	}
	
	for(ll i = 0; i < maxn; i++){
		A[i].ind = i;
		A[i].r = Un[i].R;
	}
	
	initialize();
	
	sort(A, A + maxn, greater<pll>());
	
	for(ll i = 1; i < maxn; i++){
		if(t[A[i].ind] == 0) break;
		fix(A[i].ind, A[i - 1].ind);
	}
	
	for(ll i = 0; i < maxn; i++){
		mx[root(i)] = max(mx[root(i)], t[i]);
	}
	
	for(ll i = 0; i < maxn; i++){
		ans += mx[i];
	}
	
	cout << n - ans;
	
	return 0;
}