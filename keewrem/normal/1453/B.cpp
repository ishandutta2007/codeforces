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
        cin >> N;
        vll v(N);
        for(auto &x: v)cin >> x;
        if(N == 2){
            cout << "0\n";
            continue;
        }
        ll s =0;
        for(int i = 1; i < N; i++){
            s+=abs(v[i]-v[i-1]);
        }
        ll ans = s;
        for(int i = 1; i < N-1; i++){
            ans = min (ans,s-abs(v[i]-v[i-1])-abs(v[i]-v[i+1])+abs(v[i+1]-v[i-1]));
        }
        ans = min(ans,s-abs(v[0]-v[1]));
        ans = min(ans, s-abs(v[N-1]-v[N-2]));
        cout << ans <<"\n";
    }
    return 0;
}