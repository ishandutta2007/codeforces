#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y);}
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y);}
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto kill = [](){
	    cout << "YES";
	    exit(0);
	};
	vs a(20);
	for(int i = 0; i < 5; ++ i){
		a[i] = string(20, 'O');
	}
	for(int i = 5; i < 15; ++ i){
		cin >> a[i];
		a[i].append(5, 'O');
		a[i].insert(0, 5, 'O');
	}
	for(int i = 15; i < 20; ++ i){
		a[i] = string(20, 'O');
	}
	for(int i = 5; i < 15; ++ i){
		for(int j = 5; j < 15; ++ j){
			if(a[i][j] == '.'){
				a[i][j] = 'X';
				for(int k = -4; k <= 0; ++ k){
					bool ok = true;
					for(int l = i + k; l < i + k + 5; ++ l){
						if(a[l][j] != 'X'){
							ok = false;
							break;
						}
					}
					if(ok) kill();
					ok = true;
					for(int l = j + k; l < j + k + 5; ++ l){
						if(a[i][l] != 'X'){
							ok = false;
							break;
						}
					}
					if(ok) kill();
					ok = true;
					for(int l1 = i + k, l2 = j + k; l1 < i + k + 5; ++ l1, ++ l2){
						if(a[l1][l2] != 'X'){
							ok = false;
							break;
						}
					}
					if(ok) kill();
					ok = true;
					for(int l1 = i + k, l2 = j - k; l1 < i + k + 5; ++ l1, -- l2){
						if(a[l1][l2] != 'X'){
							ok = false;
							break;
						}
					}
					if(ok) kill();
				}
				a[i][j] = '.';
			}
		}
	}
	cout << "NO";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////