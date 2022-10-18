#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int max_size = v[n-1];
    int singles = 2*k - n;
    for (int i = 0; i < (n - singles) / 2; i++)
        max_size = max(max_size, v[i] + v[n-singles-i-1]);

    cout << max_size;
}