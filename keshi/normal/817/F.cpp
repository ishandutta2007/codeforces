//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n;
Tree<ll> s;

void ch(ll x){
    if(s.find(x) == s.end()) s.insert(x);
    else s.erase(x);
    return;
}
void ch2(ll l, ll r){
    while(*s.find_by_order(s.order_of_key(l)) <= r){
        l = *s.find_by_order(s.order_of_key(l));
        s.erase(l);
    }
    return;
}

int main(){
    ll x, t, l, r;;
	fast_io;
	s.insert(0ll);
	s.insert(1ll);
	s.insert(inf);
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> t >> l >> r;
		if(t == 1){
		    x = s.order_of_key(r + 2);
			if(s.order_of_key(l + 1) % 2 == 0) ch(l);
			ch2(l + 1, r);
			if(x % 2 != s.order_of_key(r + 2) % 2) ch(r + 1);
		}
		else if(t == 2){
		    x = s.order_of_key(r + 2);
			if(s.order_of_key(l + 1) % 2 == 1) ch(l);
			ch2(l + 1, r);
			if(x % 2 != s.order_of_key(r + 2) % 2) ch(r + 1);
		}
		else{
			ch(l);
			ch(r + 1);
		}
		cout << *s.find_by_order(1) << '\n';
	}
	
	return 0;
}