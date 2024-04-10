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
        ll sum = 0;double kek = 0;
        for(auto &x: v){cin >> x; sum += x;}
        if(sum == K)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}