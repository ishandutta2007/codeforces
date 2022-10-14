#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

ll gcd(ll a, ll b){
    return a?gcd(b%a,a):b;
}
int main(){
    int N,M; cin >> N >> M;
    vector<ll> v(N);
    ll g = 0;
    for(auto &x: v)cin >> x;
    for(int i = 1; i < N; i++) g = gcd(g,abs(v[i]-v[i-1]));
    ll a;
    while (M--){
        cin >> a;
        cout << gcd((a+v[0]),g)<<" ";
    }
}