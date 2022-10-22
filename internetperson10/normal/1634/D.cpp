#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ask(int x, int y, int z) {
    cout << "? " << x << ' ' << y << ' ' << z << endl;
    int g;
    cin >> g;
    return g;
}

void answer(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 1; i <= n; i++) {
            v[i-1] = i;
        }
        while(v.size() > 2) {
            if(v.size() == 3) {
                for(int i = 1; i <= n; i++) {
                    if(v[0] != i && v[1] != i && v[2] != i) {
                        v.push_back(i);
                        break;
                    }
                }
            }
            vector<int> tent(4);
            vector<pair<int, int>> ans(4);
            for(int i = 1; i <= 4; i++) {
                tent[i-1] = v[v.size()-i];
            }
            for(int i = 1; i <= 4; i++) v.pop_back();
            for(int i = 0; i < 4; i++) {
                ans[i].first = ask(tent[(i+1)%4], tent[(i+2)%4], tent[(i+3)%4]);
                ans[i].second = tent[i]; 
            }
            sort(ans.rbegin(), ans.rend());
            v.push_back(ans[3].second);
            if(ans[2].first != ans[1].first) v.push_back(ans[2].second);
        }
        if(v.size() == 1) {
            if(v[0] == 1) v.push_back(2);
            else v.push_back(1);
        }
        answer(v[0], v[1]);
    }
}