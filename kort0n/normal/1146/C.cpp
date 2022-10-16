#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int T;
    cin >> T;
    for(int time = 1; time <= T; time++) {
        int N;
        cin >> N;
        int ans = 0;
        for(int index = 0; index <= 8; index++) {
            set<int> a;
            set<int> b;
            for(int i = 1; i <= N; i++) {
                if(1 & (i >> index)) a.insert(i);
                else b.insert(i);
            }
            if(a.empty() || b.empty()) continue;
            cout << a.size() << " " << b.size();
            for(auto itr = a.begin(); itr != a.end(); itr++) {
                cout << " " << *itr;
            }
            for(auto itr = b.begin(); itr != b.end(); itr++) {
                cout << " " << *itr;
            }
            cout << endl;
            int d;
            cin >> d;
            if(d == -1) return 0;
            ans = max(ans, d);
        }
        cout << -1 << " " << ans << endl;
    }
    return 0;
}