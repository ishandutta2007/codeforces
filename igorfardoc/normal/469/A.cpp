#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<bool> used(n, false);
    for(int i = 0; i < 2; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int a;
            cin >> a;
            --a;
            used[a] = true;
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
}