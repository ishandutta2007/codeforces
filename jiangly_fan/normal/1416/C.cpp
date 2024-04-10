#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000;
int a[maxn], p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x = 0;
    cin >> n;
    for(int i = 0; i < n; i += 1){
        cin >> a[i];
        p[i] = i;
    }
    LL ans = 0;
    for(int i = 0; i < 30; i += 1){
        sort(p, p + n, [&](const int& x, const int& y){
            int Lx = a[x] >> (i + 1), Ly = a[y] >> (i + 1);
            return Lx != Ly ? Lx < Ly : x < y;
        });
        LL p0 = 0, sum0 = 0, p1 = 0, sum1 = 0;
        for(int L = 0, R = 0; L < n; L = R){
            while(R < n and (a[p[R]] >> (i + 1)) == (a[p[L]] >> (i + 1))) R += 1;
            for(int j = L; j < R; j += 1){
                if((a[p[j]] >> i) & 1){
                    p0 += 1;
                    sum1 += p1;
                }
                else{
                    p1 += 1;
                    sum0 += p0;
                }
            }
            p0 = p1 = 0;
        }
        ans += min(sum0, sum1);
        if(sum1 < sum0) x += 1 << i;
    }
    cout << ans << " " << x;
    return 0;
}