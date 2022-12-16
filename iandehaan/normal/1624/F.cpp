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

    int n;
    cin >> n;
    int lo = 0;
    int hi = n;
    int lastans = 0;
    
    for (int currq = 0; currq < 10; currq++) {
        int mid = (lo+hi)/2;
        int diff = n-mid;
        // Just in case?
        while (diff >= n) diff--;
        while (diff <= 0) diff++;

        cout << "+ " << diff << endl;
        int ans;
        cin >> ans;

        if (ans == lastans) {
            // Didn't go up.. in first half
            // So i was in [low, mid]

            // case 1: [0, n/2)
            // Go up [n/2, n)
            hi = mid;

            // case 2: We know we were in [0, n/2)
            // We find out now we were actually in [0, n/4)
            // We added 3n/4, so we are now in [3n/4, n)
        } else {
            // Went up... in last half

            // case 1: [n/2, n)
            // Go down.. [0, n/2)
            lo = mid;
        }
        lo += diff;
        hi += diff;
        while (lo >= n) lo -= n;
        while (hi > n) hi -= n;

        lastans = ans;
    }

    cout << "! " << lastans*n + lo << endl;
}