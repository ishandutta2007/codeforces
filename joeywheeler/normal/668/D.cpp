#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;

map<int,os> ins;
map<int,os> del;

int main() {
    int n; scanf("%d", &n);
    FO(z,0,n) {
        int a, t, x; scanf("%d%d%d", &a, &t, &x);
        if (a == 1) {
            ins[x].insert(t);
        } else if (a == 2) {
            del[x].insert(t);
        } else {
            printf("%d\n", (int)ins[x].order_of_key(t) - 
                    (int)del[x].order_of_key(t));
        }
    }
}