#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> nums;
        vector<int> pos(n, -1);
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < n; j++) {
                if(s[j] == (i + '0')) nums.push_back(i);
            }
        }
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] - '0' == nums[j]) {
                pos[i] = 1;
                j++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(pos[i] == 1) continue;
            if(s[i] - '0' == nums[j]) {
                pos[i] = 2;
                j++;
            }
        }
        if(j != n) {
            cout << "-\n";
            continue;
        }
        for(int i = 0; i < n; i++) {
            cout << pos[i];
        }
        cout << '\n';
    }
}