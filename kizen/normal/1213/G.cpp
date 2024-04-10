#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
long long n, m;
long long num[200004];
long long rk[200004];
long long from[200004];
long long Ans[200004];

struct data
{
    long long a, b, w;

    bool operator<(const data&r)const{
        return w < r.w;
    }
}arr[200004];

long long Find(long long x)
{
    if (x == from[x]) return x;
    return from[x] = Find(from[x]);
}

long long hap(long long x, long long y)
{
    long long a, b;

    a = Find(x);
    b = Find(y);
    long long rv = rk[a] * rk[b];
    if(rk[a] > rk[b]){
        rk[a] += rk[b];
        from[b] = a;
    }
    else{
        rk[b] += rk[a];
        from[a] = b;
    }
    return rv;
}

int main()
{
    long long i;
    long long ans = 0;

    scanf("%lld %lld", &n, &m);
    for (i = 1; i < n; i++) {
        scanf("%lld %lld %lld", &arr[i].a, &arr[i].b, &arr[i].w);
    }
    for (i = 1; i <= n; i++) {
        num[i] = from[i] = i;
        rk[i] = 1;
    }
    sort(arr + 1, arr + n);

    for (i = 1; i < n; i++) {
        ans = (ans + hap(arr[i].a, arr[i].b));
        Ans[arr[i].w] = ans;
    }
    for(int i = 1; i <= 200000; ++i){
        if(!Ans[i]) Ans[i] = Ans[i - 1];
    }
    for(int i = 1; i <= m; ++i){
        int val; scanf("%d", &val);
        printf("%lld ", Ans[val]);
    }
    return 0;
}