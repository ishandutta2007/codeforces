#include <bits/stdc++.h>

using namespace std;

set<int> s;
int gt[200001], ans[200001];
vector<int> v;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> x;
            if(s.find(x) == s.end()) {
                s.insert(x);
                gt[i] = x;
            }
            else gt[i] = -x;
        }
        cout << s.size() << '\n';
        int j = 1;
        for(int i = 1; i <= n; i++) {
            if(gt[i] < 0) {
                while(s.find(j) != s.end()) j++;
                ans[i] = j;
                j++;
            }
            else {
                ans[i] = gt[i];
            }
        }
        int sam = 0;
        for(int i = 1; i <= n; i++) {
            if(ans[i] == i) {
                sam++;
                x = i;
            }
        }
        if(sam == 1) {
            int y;
            for(int i = 1; i <= n; i++) {
                if(gt[i] == -gt[x] && x != i) y = i;
            }
            swap(ans[x], ans[y]);
        }
        else if(sam > 1) {
            for(int i = 1; i <= n; i++) {
                if(ans[i] == i) v.push_back(i);
            }
            ans[v[0]] = ans[v[v.size()-1]];
            for(int i = 1; i < v.size(); i++) {
                ans[v[i]] = v[i-1];
            }
        }
        vector<int>().swap(v);
        for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
        set<int>().swap(s);
    }
}