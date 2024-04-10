#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ac;
vector<int> curr, curr2, cool;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cool.resize(n, -1234567890);
        int k;
        cin >> k;
        ac.resize(k);
        for(int i = 0; i < k; i++) {
            cin >> ac[i].second;
            ac[i].second--;
        }
        for(int i = 0; i < k; i++) {
            cin >> ac[i].first;
        }
        sort(ac.begin(), ac.end());
        ac.push_back({1234567890, 0});
        int x = 1;
        int temp = ac[0].first;
        curr.push_back(ac[0].second);
        for(int i = temp; curr.size(); i++) {
            while(ac[x].first == i) {
                curr.push_back(ac[x].second);
                x++;
            }
            for(int j : curr) {
                if(cool[j] > -1234567890) continue;
                cool[j] = i;
                curr2.push_back(j);
            }
            vector<int>().swap(curr);
            for(int j : curr2) {
                if(j > 0) curr.push_back(j-1);
                if(j < n-1) curr.push_back(j+1);
            }
            vector<int>().swap(curr2);
        }
        for(int i = 0; i < n; i++) {
            cout << cool[i] << ' ';
        }
        cout << '\n';
        vector<pair<int, int>>().swap(ac);
        vector<int>().swap(cool);
    }
}