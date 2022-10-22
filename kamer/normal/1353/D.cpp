#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

class Comparator
{

public:
    bool operator() (tuple<ll, ll> a, tuple<ll, ll> b) {
        ll aDiff = get<1>(a) - get<0>(a);
        ll bDiff = get<1>(b) - get<0>(b);
        if (aDiff == bDiff) {
            return get<0>(a) > get<0>(b);
        }
        return aDiff < bDiff;
    }
};

int main(void) {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, Comparator> ranges;
        ranges.push(make_tuple((ll)0, n));
        ll currIndex = 0;
        while (!ranges.empty()) {
            currIndex++;
            auto range = ranges.top();
            ranges.pop();
            ll left = get<0>(range), right = get<1>(range);
            ll mid = (left + right - 1) / 2;
            a[mid] = currIndex;
            if (mid > left) ranges.push(make_tuple(left, mid));
            if (right > mid + 1) ranges.push(make_tuple(mid + 1, right));
        }
        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;    
}