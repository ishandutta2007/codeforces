#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,K,T;
ll sas[200010];
int main(){
    cin >> N;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> sas[i];
        sum+=sas[i];
    }
    multiset<ll>sos;
    multiset<pair<ll,ll>> ses;
    ll lsum = 0,rsum = 0;
    ll res = (N*(N+1))/2;
    ll mm = N;

    for(int i = N-1; i >=0; i--){
        rsum+=sas[i];
        sos.insert(lsum);
        ses.insert({lsum,i});
        if(sos.count(rsum)>0){
            mm = min(mm,(*ses.lower_bound({rsum,0})).second);
        };
        lsum+=sas[i];
        res-=N-mm;
    }
    cout << res;
    return 0;
}