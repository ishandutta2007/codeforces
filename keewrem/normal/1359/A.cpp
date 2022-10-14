#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
ll N,M,K;

int main() {
    cin >> T;
    while (T--) {
        cin >> N>>M >>K;
        if(M<=N/K){
            cout << M <<"\n"; continue;
        }
        ll s = N/K;
        cout << s - ((M-s+K-2)/(K-1))<<"\n";
    }
    return 0;
}