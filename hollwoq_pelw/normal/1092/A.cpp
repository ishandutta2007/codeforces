#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

int main(){
    IOS;
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++){
            for (int c = 0; c < n/k+(i<n%k); c++) cout << (char)('a'+i);
        }
        cout << endl;
    }
    return 0;
}