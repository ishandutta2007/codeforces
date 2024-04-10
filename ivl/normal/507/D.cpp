#include <cstdio>

using namespace std;

long long n, k, m;
long long pot[100005];

long long dp1(int len, int rem){ // len = broj znamenki, rem = ostatak 
     if (len == 0) return rem == 0;
     static long long memo[1005][105];
     static bool bio[1005][105];
     long long &r = memo[len][rem];
     if (bio[len][rem]++) return r;
     for (int i = 0; i < 10; ++i) r += dp1(len - 1, (rem - i * pot[len - 1] + k) % k);
     return r;
}

long long cnt[105];
long long cnt2[105];

int main(){
    scanf("%I64d%I64d%I64d", &n, &k, &m);
    
    pot[0] = 1;
    for (int i = 1; i <= 100000; ++i) pot[i] = (pot[i - 1] * 10) % k;
    
    //if (n == 1){printf("%I64d\n", 9LL / k); return 0;}
    
    for (int t = 1; t <= n; ++t){
        for (int i = 1; i < k; ++i){
            int x = cnt[i], y = i;
            for (int j = 0; j < 10; ++j){
                int z = y + j * pot[t - 1];
                z %= k;
                cnt2[z] += x;
                cnt2[z] %= m;
            }
        }
        for (int i = 1; i < 10; ++i){
            int x = i * pot[t - 1];
            x %= k;
            ++cnt2[x];
            cnt2[x] %= m;
        }
        cnt2[0] += cnt[0] * (10 - (t == n));
        cnt2[0] %= m;
        for (int i = 0; i <= k; ++i){
            cnt[i] = cnt2[i];
            cnt2[i] = 0;
        }
    }
    
    printf("%I64d\n", cnt[0]);
    
    return 0;
}