#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> numsecs(40'002);
    ll two = 0;
    for (int i = 0; i +2 < 40'002; i+=3) {
        if (i == 0) numsecs[i] = two;
        else numsecs[i] = numsecs[i-1] + two;
        two += 2;
        numsecs[i+1] = numsecs[i] + two;
        two += 2;
        numsecs[i+2] = numsecs[i+1] + two;
    }

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        auto iter = lower_bound(begin(numsecs), end(numsecs), n);

        cout << (iter - begin(numsecs))+1 << '\n';
    }
}