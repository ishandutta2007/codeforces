#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N, Q;
    cin >> N  >> Q;
    vector<ll> v(N);
    cin >> v[0];
    for(int i = 1; i < N; i++){
        cin >> v[i];
        v[i]+= v[i-1];
    }
    ll k = 0, a;
    int ub, lb, mid;
    for(int i = 0; i < Q; i++){
        cin >> a;
        k += a; if(k >= v[N-1])k = 0;
        ub = N-1, lb = 0;
        while(ub >= lb){
            mid = (ub+lb)/2;
            if(v[mid]<=k)lb = mid+1;
            else ub = mid-1;
        }
        cout << N-ub-1<<"\n";
    }
    return 0;
}