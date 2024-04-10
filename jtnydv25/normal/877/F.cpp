#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = 1e5 + 10;
const int B = 305;
map<pair<int, int>, ll> ans;
ll pref[N], sz[N];
pair<int, int> qu[N];
int t[N], a[N];
vector<int> L[N];
int freq[N];
int partner1[N], partner2[N], self[N];
int n, q, k;
long long sm = 0;
int lft, rgt;

void add_right(int x){
	sm += freq[partner1[x]] + ((pref[x] - pref[lft - 1] == k));
	freq[self[x]]++;
	rgt++;
}
void add_left(int x){
	freq[self[x]]++;
	lft--;
	sm += freq[partner2[x - 1]];
}

void remove_left(int x){
	sm -= freq[partner2[x - 1]];
	freq[self[x]]--;
	lft++;
}

set<ll> st;
map<ll, int> mapping;

int main(){
	sd(n); sd(k);

	for(int i = 1; i <= n; i++) sd(t[i]);

	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(t[i] == 2) a[i] *= -1;
		pref[i] = pref[i - 1] + a[i];
	}
	for(int i = 0; i <= n; i++) st.insert(pref[i]);
	int cnt = 0;
	for(ll x : st) mapping[x] = ++cnt;

	for(int i = 0; i <= n; i++){
		partner1[i] = mapping[pref[i] - k];	
		partner2[i] = mapping[pref[i] + k];
		self[i] = mapping[pref[i]];
	}
	sd(q);
	for(int i = 1; i <= q; i++){
		int l, r;
		sd(l); sd(r);
		L[r].pb(l);
		qu[i] = {l, r};
	}

	for(int i = 0; i * B + 1 <= n; i++){
		memset(freq, 0, sizeof freq);
		sm = 0;
		lft = i * B + 1;
		rgt = i * B;
		for(int r = i * B + 1; r <= n; r++){
			add_right(r);
			int mn = i * B + 1,  mx = i * B + B;
			for(int l : L[r]){
				if(l >= mn && l <= mx){
					while(l > lft){
						remove_left(lft);
					}

					while(l < lft){
						add_left(lft - 1);
					}

					ans[{l, r}] = sm;
				}
			}
		}
	}

	for(int i = 1; i <= q; i++) printf("%lld\n", ans[qu[i]]);
}