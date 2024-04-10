#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
// j...i -> lies between j + 1 and i - l + 1 inclusive, find the one with min mindp
const int logN = 20, N = 1e5 + 10, INF = 1e9 + 10;
int floorlog[N], rmq[logN][N], RMQ[logN][N], A[N], tree[N << 1], dp[N << 2];

void update(int s, int e, int ind, int i, int x){
    if(s > i || e < i) return;
    if(s == e){
        tree[ind] = x;
        return;
    }
    int mid = (s + e) >> 1;
    update(s, mid, ind << 1, i, x);
    update(mid + 1, e, (ind << 1) | 1, i, x);
    tree[ind] = min(tree[ind << 1], tree[(ind << 1) | 1]);
}
int get(int s, int e, int ind, int l, int r){
    if(l > e || s > r) return INF;
    if(s >= l && e <= r) return tree[ind];
    int mid = (s + e) >> 1;
    return min(get(s, mid, ind << 1, l, r), get(mid + 1, e, (ind << 1) | 1, l, r));
}
int get_min(int i, int j){
    int k = floorlog[j - i + 1];
    return min(rmq[k][i], rmq[k][j - (1 << k) + 1]);
}
int get_max(int i, int j){
    int k = floorlog[j - i + 1];
    return max(RMQ[k][i], RMQ[k][j - (1 << k) + 1]);   
}
int main(){
    for(int i = 0;i < (N << 2); i++) tree[i] = dp[i] = INF;
    for(int i = 0; i < logN; i++){
        for(int j = (1 << i); j < (1 << (i + 1)) && j < N; j++)
            floorlog[j] = i;
    }
    int n, s, l;
    sd(n); sd(s); sd(l);
    if(l > n){
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= n; i++) sd(A[i]);
    for(int i = n; i >= 1; i--){
        rmq[0][i] = RMQ[0][i] = A[i];
        for(int j = 1; i + (1 << j) <= n + 1; j++){
            int ind = i + (1 << (j - 1));
            rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][ind]);
            RMQ[j][i] = max(RMQ[j - 1][i], RMQ[j - 1][ind]);
        }
    }

    for(int i = l; i <= n; i++){
        if(get_max(1, i) - get_min(1, i) <= s){
            dp[i] = 1;
            update(1, N, 1, i, dp[i]);
            continue;
        }
        int lo = 1, hi = i;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(get_max(mid, i) - get_min(mid, i) <= s) hi = mid;
            else lo = mid + 1;
        }
        // min of dp in interval [lo - 1, i - l] + 1
        if(lo <= i - l + 1){
            int x = get(1, N, 1, lo - 1, i - l);
            if(x >= INF) continue;
            dp[i] = x + 1;
            update(1, N, 1, i, dp[i]);
        }
    }
    if(dp[n] >= INF) dp[n] = -1;
    printf("%d\n", dp[n]);
}