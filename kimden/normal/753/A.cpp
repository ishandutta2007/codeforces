#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    int ans;
    for(ans = 0; (ans * (ans + 1)) / 2 <= n; ans++){

    }
    ans--;
    cout << ans << endl;
    for(int i = 0; i < ans - 1; i++){
        n -= (i + 1);
        cout << i + 1 << " ";
    }
    cout << n << endl;
    return 0;
}