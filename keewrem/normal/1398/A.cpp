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
ll N;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        vi v(N);
        for (auto &x : v)
            cin >> x;
        bool k = 0;
        if(v[0]+v[1]<=v[N-1]) {cout << "1 2 "<<N<<"\n";continue;}
        for (int i = 2; i < N; i++) {

            if (v[i] - v[i - 1] >= v[0]) {
                cout << 1 << " " << i  << " " << i+1 << "\n";
                k = 1;
                break;
            }

        }
        if (!k)
            cout << "-1\n";
    }

    return 0;
}