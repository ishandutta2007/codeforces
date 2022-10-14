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
ll N,D;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> D;
        vll v(N);
        for(auto &x: v)cin >> x;
        for(int i = 1; i < N; i++){
            v[0]+=min(D/i,v[i]);
            D-=min(D,v[i]*i);
        }
        cout << v[0]<<"\n";
    }
    return 0;
}