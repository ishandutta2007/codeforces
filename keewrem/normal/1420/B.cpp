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
int lb(int a){
    int k;
    for(int i = 0; i < 31; i++){
        if(a >= (1<<i))k = i;
    }
    return k;
}
int a;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vll c(31,0LL);
        while(N--){
            cin >> a;
            c[lb(a)]++;
        }

        ll ans = 0;
        for(auto x: c)ans+=x*(x-1)/2;
        cout << ans << "\n";
    }
    return 0;
}