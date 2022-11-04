/*#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, typename Cmp = less<T>> using ordered_set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename Cmp = less_equal<T>> using ordered_multiset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename T, typename Cmp = less<K>> using ordered_map = tree<K, T, Cmp, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(), order_of_key()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int m = 1;
	int am = 0;
	while(m < n) {
		m *= 2;
		++am;
	}
	vi b(m, 0);
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int _ = 0; _ < am; _++) {
		for(int i = 0; i < m; i++) {
			if((i >> _) & 1) {
				b[i] ^= b[i ^ (1 << _)];
			}
		}
	}
	for(const auto& el : b) {
		cout << el << ' ';
	}
	return 0;
	for(int i = n; i < m; i++) {
		b[i] = 0;
	}
	for(int _ = 0; _ < am; _++) {
		for(int i = 0; i < m; i++) {
			if((i >> _) & 1) {
				b[i] ^= b[i ^ (1 << _)];
			}
		}
	}
}*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1 << 19;

int n;
int a[N], b[N], ta[N], tb[N];
int c[N];

int m, lm, all1;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    ForE(i, 1, n){
        cin >> b[i];
    }

    m = 1 << __lg(n);
    if (m < n){
        m *= 2;
    }
    lm = __lg(m);
    all1 = m - 1;
    memset(ta, -1, sizeof(ta));
    memset(tb, -1, sizeof(tb));
    ForE(i, 1, n){
        tb[all1 ^ (i - 1)] = b[i];
        ta[n - i] = -2;
    }
    For(i, 0, m){
        c[all1 ^ i] = max(tb[i], 0);
    }
    For(bit, 0, lm){
        For(msk, 0, m){
            if (msk >> bit & 1){
                c[msk] ^= c[msk ^ (1 << bit)];
            }
        }
    }
    For(i, 0, m){
        if (tb[i] == -1){
            c[all1 ^ i] = 0;
        }
    }
    For(bit, 0, lm){
        For(msk, 0, m){
            if (msk >> bit & 1){
                c[msk] ^= c[msk ^ (1 << bit)];
            }
        }
    }
    For(i, 0, m){
        tb[i] = c[all1 ^ i];
    }
    For(i, 0, m){
        ta[i] = tb[i];
    }
    For(bit, 0, lm){
        For(msk, 0, m){
            if (msk >> bit & 1){
                ta[msk] ^= ta[msk ^ (1 << bit)];
            }
        }
    }
    ForE(i, 1, n){
        a[i] = ta[n - i];
    }
    ForE(i, 1, n){
        cout << a[i] << ' ';
    } cout << endl;
}