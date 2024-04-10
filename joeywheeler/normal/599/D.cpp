#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long long x;

long long rt(long long a) {
    long long s = 0, e = 1000001000, b = 0;
    while (s <= e) {
        long long m = (s+e)/2;
        if (m*m < a) {
            b = m;
            s = m+1;
        } else e = m-1;
    }
    return b;
}

int main() {
    scanf("%lld", &x);
    x *= 6;
    vector<pair<long long,long long> > ans;
    for (long long i = 1; i*i*i <= x; i++) {
        // i == n
        {
            long long n = i;
            long long l = n*(n+1);
            if (x%l == 0) {
                long long t = x / l;
                long long mm = t - 2*n - 1;
                if (mm >= 0 && mm % 3 == 0) {
                    ans.emplace_back(n, n+mm/3);
                    ans.emplace_back(n+mm/3, n);
                }
            }
        }
        // i == 3m' + (2n+1)
        {
            if (x%i == 0) {
                long long l = x/i;
                long long n = rt(l);
                l = n*(n+1);
                if (n > 0 && x%l == 0) {
                    long long t = x / l;
                    long long mm = t - 2*n - 1;
                    if (mm >= 0 && mm % 3 == 0) {
                        ans.emplace_back(n, n+mm/3);
                        ans.emplace_back(n+mm/3, n);
                    }
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    printf("%d\n", sz(ans));
    for (auto p : ans) printf("%lld %lld\n", p.first, p.second);
}