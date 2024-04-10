#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int NM = 19;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int cmp[75];
int val[75];

int dp[(1<<NM)];
int dpp[(1<<NM)];

const int MOD = 1000000007;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    return add(a, MOD-b);
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int ima[75];
int pw2[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=70; i++){
        cmp[i] = i;
        for(int j=2; j*j<=cmp[i]; j++){
            while(cmp[i]%(j*j) == 0){
                cmp[i] /= j*j;
            }
        }
        for(int j=0; j<NM; j++) if(cmp[i]%primes[j] == 0) val[i] += (1 << j);
    }
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        ima[x]++;
    }
    dpp[0] = 1;
    pw2[0] = 1;
    for(int i=1; i<=n; i++) pw2[i] = mul(pw2[i-1], 2);
    for(int j=1; j<=70; j++){
        if(ima[j]){
            for(int i=0; i<(1<<NM); i++){
                dp[i] = add(dp[i], mul(dpp[i^val[j]], pw2[ima[j]-1]));
                dp[i] = add(dp[i], mul(dpp[i], pw2[ima[j]-1]));
            }
        }
        else{
            for(int i=0; i<(1<<NM); i++) dp[i] = dpp[i];
        }
        for(int i=0; i<(1<<NM); i++){
            dpp[i] = dp[i];
            dp[i] = 0;
        }
    }
    cout << sub(dpp[0], 1) << "\n";
    return 0;
}