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

int main(){
    cin >> T;
    while(T--){
        ll K;
        cin >> K;
        if(K & 1){cout << "-1\n";continue;}
        int s = 0;
        K -= 2; K/=2; ll a = K;
        for(ll i = 60; i > 0; i--){
            while(a >= ((1LL<<i)-1)){
                s+= i; a-=((1LL<<i)-1);
            }
        }
        cout << s+1<<"\n1 ";
        for(ll i = 60; i > 0; i--){
            while(K >= ((1LL<<i)-1)){
                K-=((1LL<<i)-1);
                for(int j = 0; j < i-1; j++){
                    cout << "0 ";
                }
                cout << "1 ";
            }
        }
        cout << "\n";


    }
    return 0;
}