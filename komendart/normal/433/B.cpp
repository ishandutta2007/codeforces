#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

main()
{
    int n;
    cin >> n;
    
    int unsorted[n], sorted[n];
    for (int i = 0; i < n; i += 1)
    {
        int t; cin >> t;
        unsorted[i] = sorted[i] = t;
    }
    sort(sorted, sorted + n);
    
    int unsorted_S[n + 1], sorted_S[n + 1];
    unsorted_S[0] = sorted_S[0] = 0;
    for (int i = 1; i <= n; i += 1)
    {
        unsorted_S[i] = unsorted_S[i - 1] + unsorted[i - 1];
        sorted_S[i] = sorted_S[i - 1] + sorted[i - 1];
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i += 1)
    {
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 1) cout << unsorted_S[r] - unsorted_S[l - 1] << endl;
        else           cout << sorted_S[r] - sorted_S[l - 1] << endl;
    }
}