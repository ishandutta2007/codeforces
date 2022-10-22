#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ask(int n) {
    cout << "? " << n+1 << endl;
    int x;
    cin >> x;
    return x-1;
}

int ans(vector<int> v) {
    cout << "!";
    for(int i = 0; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n, -1);
        int q = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == -1) {
                vector<int> v;
                int x = i;
                x = ask(i);
                v.push_back(x);
                q++;
                x = ask(i);
                v.push_back(x);
                q++;
                while(x != v[0]) {
                    x = ask(i);
                    v.push_back(x);
                    q++;
                }
                int g = 0;
                for(int j = 0; j < v.size()-1; j++) {
                    nums[v[j]] = v[j+1]+1;
                }
            }
        }
        ans(nums);
        vector<int>().swap(nums);
    }
}