#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned ll
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<class T, class V, int MAX_FREE_FACTOR = (1<<20), int INIT_m = 3>
struct hash_map{
    int size, m, M;
    T * bucket;
    V * values;
    ull a;
    ull b;
    T MAX, MIN;
    int min_filled;
    void init(){
        a = uniform_int_distribution<ull>()(rng);
        if(a % 2 == 0) a++;
        b = uniform_int_distribution<ull>()(rng);
        m = INIT_m;
        M = 1 << m;
        bucket = new T[M];
        values = new V[M];
        size = 0;
        MAX = numeric_limits<T>::max();
        MIN = numeric_limits<T>::min();
        min_filled  = 0;
        fill(bucket, bucket + M, MIN);
        fill(values, values + M, numeric_limits<V>::min());
    }
 
    hash_map(){
        init();
    }
 
    //[0....M - 1]
    int h(T x){
        return (((ull) x) * a + b) >> (64 - m);
    }
    
    void rehash(int new_m){
        int oldM = M;
 
        T * bucket_copy = new T[M];
        V * values_copy = new V[M];
        copy(bucket, bucket + M, bucket_copy);
        copy(values, values + M, values_copy);
        delete [] bucket;
        delete [] values;
 
        M = (1 << new_m);
        m = new_m;
        min_filled = M / MAX_FREE_FACTOR;
        bucket = new T[M];
        values = new V[M];
        fill(bucket, bucket + M, MIN);
        fill(values, values + M, numeric_limits<V>::min());
 
        size = 0;
 
        for(int i = 0; i < oldM; i++){
            T v = bucket_copy[i];
            if(v != MIN && v != MAX) (*this)[v] = values_copy[i];
        }
 
        delete [] bucket_copy;
        delete [] values_copy;
    }
 
    V & operator [](T x){
        if(2 * size >= M){
            rehash(m + 1);
        }
        int pos = h(x);
        while(bucket[pos] != MIN){
            if(bucket[pos] == x){
                return values[pos];
            }
            pos = (pos + 1) & (M - 1);
        }
        bucket[pos] = x;
        values[pos] = numeric_limits<V>::min();
        size++;
        return values[pos];
    }
 
    bool erase(T x){
        // no point in rehashing is m is already small and (1<<m) fits into cache
        if(size < min_filled && m > INIT_m + 5){
            rehash(m - 1);
        }
        int pos = h(x);
        while(bucket[pos] != MIN){
            if(bucket[pos] == x){
                bucket[pos] = MAX;
                values[pos] = numeric_limits<V>::min();
                size--;
                return true;
            }
            pos = (pos + 1) & (M - 1);
        }
        return false;
    }
 
    void clear(){
        delete [] bucket;
        delete [] values;
        init();
    }
 
    ~hash_map(){
        delete [] bucket;
        delete [] values;
    }
};
 
 
const ll INF = 1e15 + 21;
const ll MAXN = 1e5 + 5;
typedef pair<ll, ll> pii;
typedef hash_map<int, ll, 1 << 20, 18> ht;
 
 
ll N, Q;
ll V[MAXN];
ll C[MAXN];
ll dp[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (ll i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> C[i];
    }
    
    ht curMax;
    for (ll i = 0; i < Q; i++) {
        for (int i = 0; i < N; i++) {
            curMax[C[i]] = -INF;
        }
        // for (auto j : curMax) {
        //     curMax[j.first] = -INF;
        // }
        ll a, b;
        cin >> a >> b;
        fill(dp, dp + N, -1);
        pii mx1 = {0, 1e5 + 5};
        pii mx2 = {0, 1e5 + 4};
        for (ll j = 0; j < N; j++) {
            if (mx1.second == C[j]) {
                dp[j] = mx2.first + b * V[j];
            } else {
                dp[j] = mx1.first + b * V[j];
            }
            dp[j] = max(dp[j], curMax[C[j]] + a * V[j]);
            if (dp[j] > mx1.first) {
                if (C[j] == mx1.second) {
                    mx1 = {dp[j], C[j]};
                } else {
                    mx2 = {mx1.first, mx1.second};
                    mx1 = {dp[j], C[j]};
                }
            } else if (dp[j] > mx2.first) {
                if (C[j] == mx1.second) {
                    continue;
                } else {
                    mx2 = {dp[j], C[j]};
                }
            }
            curMax[C[j]] = max(curMax[C[j]], dp[j]);
        }
        cout << mx1.first << endl;
    }
}