#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int yeet = (a[0]+a[k])/2;
        int out = max(yeet-a[0], a[k]-yeet);
        int point = yeet;
        for (int i = 1; i < n-k; i++) {
            int x = (a[i]+a[k+i])/2;
            int diff = max(x-a[i], a[k+i]-x);
            if (diff < out) {
                out = diff;
                point = x;
            }

        }
        cout << point << endl;
    }
}