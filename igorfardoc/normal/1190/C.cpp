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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int min0 = n;
    int min1 = n;
    int max0 = -1;
    int max1 = -1;
    vi pos0;
    vi pos1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            pos0.push_back(i);
            max0 = max(max0, i);
            min0 = min(min0, i);
        } else {
            pos1.push_back(i);
            max1 = max(max1, i);
            min1 = min(min1, i);
        }
    }
    if((max1 - min1 + 1 <= k) || (max0 - min0 + 1 <= k)) {
        cout << "tokitsukaze";
        return 0;
    }
    if((max1 - min1 + 1 == k + 1) && (max0 - min0 + 1 == k + 1)) {
        if(min1 < k && min0 < k && n - max1 <= k && n - max0 <= k) {
            cout << "quailty";
            return 0;
        }
    } 
    cout << "once again";
}