#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int main() {
    #ifdef LOCAL
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif    	   	

    
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);

    vector<int> t(n);
    for (int i =0 ; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    set< pair<int, int> > top;
    while (q--) {
        int type, id;
        scanf("%d%d", &type, &id);
        --id;

        if (type == 1) {
            top.insert( make_pair(t[id], id) );
            if (top.size() > k) {
                top.erase(top.begin());
            }
        } else {
            assert(type == 2);
            puts(top.find( make_pair(t[id], id) ) == top.end() ? "NO" : "YES");
        }
    }


    return 0;
}