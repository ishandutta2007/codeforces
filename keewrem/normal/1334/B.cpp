#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,T,K,a;
vector<ll> sas;
int main(){
    cin >> T;
    while(T--){
        cin >> N>>K;
        sas.clear(); sas.resize(N);
        for(int i = 0; i < N; i++){
            cin >> sas[i];
        }
        sort(sas.begin(),sas.end());
        ll sum = 0;
        bool sos = 0;
        for(int i = N-1; i >= 0; i--){
            sum +=sas[i];
            if(sum<K*(N-i)){
                cout << N - 1 - i;
                sos = 1;
                break;
            }
        }
        if(!sos)cout << N;
        cout <<"\n";
    }
    return 0;
}