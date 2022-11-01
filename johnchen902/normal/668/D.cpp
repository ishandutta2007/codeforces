#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
map<int, tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>> ins;
map<int, tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>> era;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, t, x;
        scanf("%d %d %d", &a, &t, &x);
        switch(a) {
        case 1: {
            ins[x].insert(t);
            break;
        }
        case 2: {
            era[x].insert(t);
            break;
        }
        case 3: {
            printf("%d\n", (int) (ins[x].order_of_key(t) - era[x].order_of_key(t)));
            break;
        }
        }
    }
}