//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
const int INF = 1E9;
int A[N];
int trans(string &s){
    int mult = 1,num = 0;
    for(int i = int(s.length())-1;i>=0;--i){
        if (s[i]=='-'){
            num = -num;
            break;
        }
        num+=int(s[i]-'0')*mult;
        mult*=10;
    }
    return num;
}
vector<ll> MOD = {ll(1E9+123),ll(1E9+7),998244353};
typedef tuple<ll,ll,ll> big;
ll binpow(ll x,int power,ll mod){
    ll mult = x%mod;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%mod;
        mult = mult*mult%mod;
        power = power>>1;
    }
    return x;
}
big pr(big x,int power){
    get<0>(x) = binpow(get<0>(x),power,MOD[0]);
    get<1>(x) = binpow(get<1>(x),power,MOD[1]);
    get<2>(x) = binpow(get<2>(x),power,MOD[2]);
    return x;
}
big su(big a,big b){
    big c = {(get<0>(a)+get<0>(b)+MOD[0])%MOD[0],(get<1>(a)+get<1>(b)+MOD[1])%MOD[1],(get<2>(a)+get<2>(b)+MOD[2])%MOD[2]};
    return c;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int flag = 0,cnt = 0;
    for(int i = 0;i<=n;++i){
        string s;
        cin>>s;
        if (s=="?")
            A[i] = -INF;
        else A[i] = trans(s);
        if (A[i]==-INF)
            flag = 1;
        else ++cnt;
    }
    if (flag==0){
        big sum = {0,0,0};
        for(int i = 0;i<=n;++i){
            big add = {k,k,k};
            add = pr(add,i);
            get<0>(add) = (get<0>(add)*A[i]%MOD[0])%MOD[0];
            get<1>(add) = (get<1>(add)*A[i]%MOD[1])%MOD[1];
            get<2>(add) = (get<2>(add)*A[i]%MOD[2])%MOD[2];
            sum = su(sum,add);
        }
        if (get<0>(sum)==0 && get<1>(sum)==0 && get<2>(sum)==0)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    else{
        if (k==0){
            if (A[0]!=-INF){
                if (A[0]==0)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
            }
            else{
                if (cnt%2)
                    cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
        else{
            if ((n+1)%2==0)
                cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}