#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> nums;
vector<int> loc;
vector<int> sr, sc;
vector<pair<int, int>> s;

int main() {
    int r, c;
    cin >> r >> c;
    nums.resize(r);
    sr.resize(c, 0);
    sc.resize(r, 0);
    loc.resize(r*c+1, 0);
    for(int i = 0; i < r; i++) {
        nums[i].resize(c);
        for(int j = 0; j < c; j++) {
            cin >> nums[i][j];
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sc[i] = max(sc[i], nums[i][j]);
            sr[j] = max(sr[j], nums[i][j]);
            nums[i][j] = 0;
        }
    }
    sort(sr.rbegin(), sr.rend());
    sort(sc.rbegin(), sc.rend());
    for(int i = 0; i < r; i++) {
        loc[sc[i]] += i;
    }
    for(int i = 0; i < c; i++) {
        loc[sr[i]] += i * 10000;
    }
    //for(int i = 1; i <= r*c; i++) cout << loc[i] << '\n';
    //cout << "Bruh\n";
    int x = 0, y = 0, pos = 0;
    s.push_back({x, y});
    for(int i = r*c; i > 0; i--) {
    //    cout << i << '\n';
        if(loc[i] > 0) {
            int ax = loc[i]%10000, ay = loc[i]/10000;
    //        cout << ax << ' ' << ay << '\n';
            if(ax > 0) {
                for(int j = x+1; j <= ax; j++) {
                    for(int k = y; k >= 0; k--) {
                        s.push_back({j, k});
                    }
                }
                x = ax;
            }
            if(ay > 0) {
                for(int j = x; j >= 0; j--) {
                    for(int k = y+1; k <= ay; k++) {
                        s.push_back({j, k});
                    }
                }
                y = ay;
            }
            nums[x][y] = i;
   //         cout << "new " << i << ' ' << x << ' ' << y << '\n';
        }
        else {
            while(nums[s[pos].first][s[pos].second] > 0) pos++;
            nums[s[pos].first][s[pos].second] = i;
        }
    //    cout << s.size() << '\n';
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << nums[i][j] << ' ';
        }
        cout << '\n';
    }
}