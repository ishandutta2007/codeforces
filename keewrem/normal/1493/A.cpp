#include <bits/stdc++.h>

using namespace std;

#define MOD 1e9+7
#define MAXN 1e6
#define F first
#define S second
#define PB push_back

typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef pair<int,pi> ipi;
typedef vector<pi> vpi;
typedef vector<pii> vpii;
typedef vector<ipi> vipi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

int T;


int main(){
    T = 1;
    cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        vi ris;
        for(int i = n; i >= 1; i--){
            if (i == k) continue;
            if (2*i < k) continue;
            ris.PB(i);
        }
        cout << ris.size() << "\n";
        for(auto u : ris) cout << u << "\n";
    }

    return 0;
}