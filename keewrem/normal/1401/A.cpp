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
ll N,K;

int main(){
    cin >> T;
    while(T--){
        cin >> N>>K ;
        if(K<=N){
            if((N-K)%2==0)cout << "0\n";
            else cout << "1\n";
        }else cout << K-N << "\n";
    }
    return 0;
}