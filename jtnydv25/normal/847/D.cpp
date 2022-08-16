#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &x)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
int cnt = 0;
int main(){
    int n, T, t;
    sd(n); sd(T);
    ordered_set os;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        sd(t);
        os.insert({t - i, ++cnt});
        int wait = T - i - 1;
        if(wait >= 0) ans = max(ans, (int)os.order_of_key({wait + 1, -1}));
    }
    printf("%d\n", ans);
}