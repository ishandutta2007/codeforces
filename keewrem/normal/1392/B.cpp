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
        cin >> N >> K;
        vll v(N);
        ll m = -1000000000;
        for(auto &x: v){cin >> x; m = max(x,m);}

        for(auto &x: v)x = m-x;
        K--;
        m = -1000000000;
        if(K-->0){
            for(auto x: v)m = max(x,m);
            for(auto &x: v)x = m-x;
        }
        K %= 2;
        if(K>0){
            for(auto x: v)m = max(x,m);
            for(auto &x: v)x = m-x;
        }
        for(auto x: v)cout << x << " ";
        cout << endl;
    }
    return 0;
}