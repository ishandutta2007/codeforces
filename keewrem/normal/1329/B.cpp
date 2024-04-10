#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll T,N,K,D,M;
int main(){
    cin >> T;
    while(T--){
        cin >> D >> M;
        vector<long long> v;
        for(int i = 0; i < 31; i++){
            if(D < 1LL<<(i+1)){
                v.push_back(D-(1LL<<i)+1);
                break;
            }
            v.push_back(1LL<<i);
        }
        ll res = 1;
        for(auto x: v){
            res*=(x+1);
            res%=M;
        }

        cout << (res+M-1)%M <<"\n";
    }
    return 0;
}