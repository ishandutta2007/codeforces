#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        vector<int> b;
        while (l <= r)
        {
            b.push_back(a[l]);
            l++;
            if (l > r) break;
            b.push_back(a[r]);
            r--;
        }
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << "\n";
    }
}