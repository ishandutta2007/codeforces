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
        vll v(N);
        for(auto &x: v)cin >> x;
        ll ans = 0;
        for(int i = 0; i < N-1; i++){
            if(v[i]-v[i+1]>0)ans+=v[i]-v[i+1];
        }
        cout << ans << endl;
    }
    return 0;
}