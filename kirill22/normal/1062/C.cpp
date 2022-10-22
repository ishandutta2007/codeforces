#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
inline void Routine() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}
const long long MOD=1e9+7;
int ct[1000]={0};
int main() {
    Routine();

    int n,q;
    cin >> n >> q;
    string s;
    cin  >> s;
    ll kol[n+1];
    kol[0]=0;
    for(int i=1;i<=n;i++){

        kol[i]=kol[i-1];
        if (s[i-1]=='1'){
            kol[i]++;
        }

    }
    ll cnt[kol[n]+1];
    ll j=1;
    cnt[0]=0;
    for(int i=0;i<kol[n];i++){
        cnt[i+1]=(j+cnt[i])%MOD;
        j+=j;
        j%=MOD;

    }
    ll dv[100001];
    dv[0]=1;
    for(int u=1;u<100001;u++){
        dv[u]=(dv[u-1]*2)%MOD;
    }


    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        int k=y-x+1;
        ll ans=0,ansi=0;
        ansi=kol[y]-kol[x-1];


        ans=(ans+cnt[ansi])%MOD;
        ll p=k-ansi;

        ans=(ans*(((dv[p]-1)%MOD)+1))%MOD;

        cout << ans << endl;

    }
    return 0;
}