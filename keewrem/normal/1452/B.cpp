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
        ll mx = 0, s = 0;
        for(auto &x: v){
            cin >> x; mx= max(mx,x);
            s+=x;
        }
        if(s >= (N-1)*mx)cout << (N-1-(s%(N-1)))%(N-1)<<"\n";
        else cout << mx*(N-1)-s<<"\n";
    }
    return 0;
}