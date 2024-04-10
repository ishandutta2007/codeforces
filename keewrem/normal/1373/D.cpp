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

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vll v(N), pf(N);

        for(int i = 0; i < N; i++)cin >> v[i];

        pf[0] = -v[0]; ll p = pf[0], d = 0;
        ll ans = 0;
        for(int i = 1; i < N; i++){
            if(i&1){pf[i]=pf[i-1]+v[i]; d = min(pf[i],d);ans = max(pf[i]-d,ans);}
            else{pf[i]=pf[i-1]-v[i]; p = min(pf[i],p);ans = max(pf[i]-p,ans);}
        }
        for(int i = 0; i < N; i+=2)ans+=v[i];
        cout << ans <<"\n";
    }
    return 0;
}