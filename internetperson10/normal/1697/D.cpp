#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

char ask1(int x) {
    cout << "? " << 1 << ' ' << x+1 << endl;
    char c;
    cin >> c;
    return c;
}

int ask(int l, int r) {
    cout << "? " << 2 << ' ' << l+1 << ' ' << r+1 << endl;
    int x;
    cin >> x;
    return x;
}

int la[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int best = 0;
    char ans[n];
    for(int i = 0; i < 26; i++) la[i] = n;
    for(int i = n-1; i >= 0; i--) {
        int x = ask(i, n-1);
        if(x > best) {
            ans[i] = ask1(i);
            best = x;
            la[ans[i] - 'a'] = i;
        }
        else {
            vector<int> nums;
            for(int i = 0; i < 26; i++) {
                if(la[i] != n) nums.push_back(la[i]);
            }
            sort(nums.begin(), nums.end());
            int l = -1, r = nums.size() - 1;
            while(l != r - 1) {
                int mid = (l + r + 1) / 2;
                int x = ask(i, nums[mid]);
                if(x == mid + 2) l = mid;
                else r = mid;
            }
            ans[i] = ans[nums[r]];
            la[ans[i] - 'a'] = i;
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << ans[i];
    cout << endl;
}