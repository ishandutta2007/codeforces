#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef long double ld;

ll niz[300005];
ll ima[605][605];
ll res[300005];
ll dp[300005];

struct strukt{
    int a, b, ind;
} query[300005];

bool cmp(strukt a, strukt b){
    return a.b < b.b;
}

const int k = 600;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        cin >> query[i].a >> query[i].b;
        query[i].ind = i;
    }
    sort(query+1, query+1+q, cmp);
    for(int i=1; i<=q; i++){
        if(query[i].b > k){
            ll sum = 0;
            int a = query[i].a;
            int b = query[i].b;
            for(int j=a; j<=n; j+=b){
                sum += niz[j];
            }
            res[query[i].ind] = sum;
        }
        else if(query[i].b == query[i-1].b){
            res[query[i].ind] = dp[query[i].a];
        }
        else{
            int b = query[i].b;
            for(int j=n; j>=1; j--){
                if(j+b > n) dp[j] = niz[j];
                else dp[j] = niz[j] + dp[j+b];
            }
            res[query[i].ind] = dp[query[i].a];
        }
    }
    for(int i=1; i<=q; i++) cout << res[i] << "\n";
    return 0;
}