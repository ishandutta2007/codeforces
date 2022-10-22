#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, arr[202020];
int mx, mxp, cur;
bool flag = false;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
            mxp = i;
        }
    }

    for (int i=0; i<mxp-1; i++) {
        if (arr[i] > arr[i+1]) {
            flag = true;
            break;
        }
    }

    for (int i=mxp; i<n-1; i++) {
        if (arr[i] < arr[i+1]) {
            flag = true;
            break;
        }
    }

    if (flag) cout << "NO";
    else cout << "YES";
}