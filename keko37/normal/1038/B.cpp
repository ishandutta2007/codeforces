#include<bits/stdc++.h>

using namespace std;

int n;

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    if (n <= 2) {
        cout << "No";
        return 0;
    }
    int sum = n*(n+1)/2;
    for (int i=2; i<=n; i++) {
        if (sum % i == 0) {
            cout << "Yes" << endl;
            cout << 1 << " " << i << endl;
            cout << n-1 << " ";
            for (int j=1; j<=n; j++) {
                if (j != i) cout << j << " ";
            }
            break;
        }
    }
	return 0;
}