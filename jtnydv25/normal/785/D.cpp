#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
const int N = 5e5; 
int fact[N], invfact[N];
inline int add(int a, int b){ a += b; if(a >= mod) a -= mod; return a;}
inline int mul(int a, int b){ return (a*1ll*b)%mod;}
inline int powr(int a, int b){
    int x = 1;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
inline int C(int a, int b){
    if( a < b || b < 0) return 0;
    return mul(fact[a], mul(invfact[b], invfact[a - b]));
}

char s[N];
int main(){
    fact[0] = invfact[0] = 1;
    for(int i = 1;i < N; i++) fact[i] = mul(fact[i - 1], i), invfact[i] = inv(fact[i]);
    scanf("%s", s);
    string S = (string)s;
    int x = 0, y = count(S.begin(), S.end(), ')'), ans = 0;
    for(int i = 0;i<S.length(); i++){
        if(S[i] == '(') ans = add(ans,C(x + y, y - 1)), x ++;
        else y --;
    }
    printf("%d\n", ans);
}