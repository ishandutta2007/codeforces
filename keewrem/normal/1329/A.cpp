#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;

ll T,N,K;
ll sus = 0;
int main(){
    cin >> N >> T;
    ll sas[T];
    ll res[N];
    for(int i = 0; i < T; i++){
        cin>>sas[i];
        sus += sas[i];
    }
    ll pos = 0;
    vi ans;
    if(sus < N){cout << "-1"; return 0;}
    for(ll i = 0; i < T; i++){
        pos = max(pos+1,N-sus+1);
        if(sus < N-pos+1 || pos > N-sas[i]+1){cout << "-1"; return 0;}
        sus-=sas[i];
        ans.push_back(pos);
    }
    for(auto x: ans)cout << x<< " ";
    return 0;
}