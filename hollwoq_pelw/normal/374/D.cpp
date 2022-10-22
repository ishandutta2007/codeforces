/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds; 
 
#include<bits/stdc++.h>
using namespace std;

template <class T> 
using ordered_set = tree<T, null_type, less<T>, 
		rb_tree_tag, tree_order_statistics_node_update>;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

const int N = 1e6 + 5;

int n, m, a[N];

void Hollwo_Pelw() {
	ordered_set<pair<int, int>> st;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		if (x == -1) {
			for (int j = 1; j <= m; j++) {
				if (st.size() <= a[j] - j)
					break ;
				st.erase(st.find_by_order(a[j] - j));
			}
		} else {
			st.insert({i, x});
		}
	}
	if (st.empty())
		return cout << "Poor stack!", (void) 0;
	for (auto v : st)
		cout << v.second;
}