#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T = 1;
ll N;
int p[1000001];
int sqf[1000001];
void solve(){
    cin >> N;
    vi v(N);
    for(auto &x: v){
        cin >> x;
        x = sqf[x];
    }

    int z = 0, c = 1, m = 0,md = 0;
    sort(v.begin(),v.end());
    for(int i = 1; i < N; i++){
    //    cout << v[i]<<" ";
        if(v[i] == v[i-1])c++;
        else {
            m = max(c,m);
            if(c % 2 == 0 || v[i-1]==1)z+=c;
            else md = max(c,md);
            c = 1;
        }
    }
//    cout <<"\n";
    m = max(c,m);
    if(c % 2 == 0 || v[N-1]==1)z+=c;
    else md = max(c,md);
    int q; cin >> q;    ll a;
    //cout << "z "<<z <<" md "<<md << " m "<<m <<"\n";
    while(q--){

        cin >> a;
        if(a == 0)cout << m <<"\n";
        else cout << max(z,md)<<"\n";
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    p[1] = 1;
    for(int i = 2; i < 1000001; i++){
        if(p[i])continue;
        for(int j = i; j < 1000001; j+=i)p[j] = i;
    }
    for(int i = 1; i <1000001; i++){
        sqf[i] = i; int k = 1;
        while(sqf[i] > 1){
            if((sqf[i] % (p[sqf[i]]*p[sqf[i]])) == 0){
                sqf[i] /= (p[sqf[i]]*p[sqf[i]]);
            }else{
                k*=p[sqf[i]];
                sqf[i] /= p[sqf[i]];
            }

        }
        sqf[i] = k;
    }

    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}