#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
ll N,M,t;

int main(){
    cin >> N >> M;
    ll P[N];
    for(int i = 0; i <N; i++)cin >> P[i];
    ll r1 =0;
    ll res = 1;
    ll count = 0;
    for(ll i = 0; i < M; i++)r1+=N-i;
    bool k = 0;
    for(int i = 0; i <N; i++){
        if(P[i]>N-M)k = 1;
        if(!k)continue;
        count ++;
        if(P[i]>N-M){
            res*=count;
            res%=998244353;
            count = 0;
        }
    }
    cout << r1 << " " << res<<"\n";
    return 0;
}