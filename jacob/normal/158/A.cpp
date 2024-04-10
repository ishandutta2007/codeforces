#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> sc(n);
    for (int i = 0; i < n; i++)
        cin >> sc[i];
    nth_element(sc.begin(), sc.begin() + n - k, sc.end());
    int u = max(1, sc[n-k]);
    int res = 0;
    for (int i = 0; i < n; i++)
        if (sc[i] >= u) ++res;
    cout << res << endl;
    return 0;
}