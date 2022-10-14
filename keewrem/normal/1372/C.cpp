#include<bits/stdc++.h>
#define pb push_back
#define MAXN 200010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vll;
const ll MOD = 1000000007;

ll sum(ll a, ll b){
    while(a+b>MOD)a-=MOD;
    return a+b;
}

ll mult(ll a, ll b){
    return (a*b)%MOD;
}

ll fexp(ll base, ll exp){
    ll r = 1;
    for(ll i = 1; i <= exp; i<<=1){
        if(i&exp)r=mult(r,base);
        base=mult(base,base);
    }
    return r;
}

ll inv(ll a){
    return fexp(a,MOD-2);
}

ll fact[MAXN]; ll finv[MAXN];
void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++){
        fact[i]=mult(fact[i-1],i);
    }
    finv[MAXN-1]=inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i; i--){
        finv[i] = mult(finv[i+1],i);
    }
}

ll bin(ll a, ll b){
    if(b > a)return 0;
    return mult(fact[a], mult(finv[b],finv[a-b]));
}

ll N,T,M,K,a,b,c;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        for(auto &x: v)cin >> x;
        int c = 0;
        bool q = 0;
        vi lol;
        for(int i = 0; i < N; i++){
            if(v[i]==i+1)c++;
            else lol.pb(i);
        }
        for(int i = 1;i < lol.size(); i++)if(lol[i]-lol[i-1]!=1)q = 1;
        if(c == N)cout << "0\n";
        else if(c==0||(q==0))cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}