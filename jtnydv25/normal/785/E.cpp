#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 2e5 + 10;
int SN;
ordered_set s[5000];
int A[N];
inline int block(int i){ return (i - 1)/SN + 1;}
inline int f(int i){
    int ans = 0, ele = A[i];
    for(int b = 1;;b++){
        int l = (b - 1)*SN + 1, r = b*SN;
        if(r < i) ans += s[b].order_of_key(ele);
        else{
            for(int j = l; j < i; j ++) if(A[j] < ele) ans ++;
            return ans;
        }
    }
}
inline int num(int i){
    int fi = f(i);
    return i - 1 - fi + A[i] - 1 - fi;
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    SN = (int)sqrt(50 * n);
    for(int i = 1; i <= n; i++) A[i] = i;
    for(int i = 1;i <= n; i += SN){
        int b = block(i);
        for(int j = i;j <= i + SN - 1 && j <= n; j++) s[b].insert(j);
    }
    ll ans = 0;
    while(q--){
        int i, j;
        scanf("%d %d", &i, &j);
        if(i > j) swap(i, j);
        ans -= (num(i) + num(j) - (A[i] > A[j]));
        s[block(i)].erase(A[i]); s[block(j)].erase(A[j]);
        swap(A[i], A[j]);
        s[block(i)].insert(A[i]); s[block(j)].insert(A[j]);
        ans += (num(i) + num(j) - (A[i] > A[j]));
        printf("%lld\n", ans);
    }
}