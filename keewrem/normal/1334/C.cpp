#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,T,K;
int nx(ll a){
    if(a == N-1)return 0;
    return a+1;
}
ll a[400000], b[400000], v[400000];
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            scanf("%lld %lld", &a[i], &b[i]);

        }
        ll best = -10000000000000; int ind = 0;
        for(int i = 0; i < N; i++){
            if(max(0LL,a[nx(i)]-b[i])-a[nx(i)]>best){
                best = max(0LL,a[nx(i)]-b[i])-a[nx(i)];
                ind = nx(i);
            }
        }
        ll res = 0;
        bool sas = 1;
        for(int i = ind; i!=ind || sas; i=nx(i)){
            sas=0; res+=a[i]; a[nx(i)]=max(0LL,a[nx(i)]-b[i]);
        }
        cout << res <<"\n";
    }
    return 0;
}