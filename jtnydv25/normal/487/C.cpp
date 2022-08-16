#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

int mod;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
bool prime(int n){
    for(int i = 2; i * i <= n; i++) if(n % i == 0) return 0;
    return 1;
}
int main(){
    int n;
    cin >> n;
    if(n == 1){
        printf("YES\n1\n");
        return 0;
    }
    if(n == 4){
        printf("YES\n1\n3\n2\n4\n");
        return 0;
    }
    if(!prime(n)){
        printf("NO"); return 0;
    }
    printf("YES\n1\n");
    mod  = n;
    for(int i = 2; i < n; i++){
        printf("%d\n", mul(i, inv(i - 1)));
    }
    printf("%d\n", n);
}