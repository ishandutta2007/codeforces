#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ma.resize(10);
    for(int i = 1; i < 10; i++) cin >> ma[i];
    for(int i = 0; i < n; i++) {
        int x = s.at(i) - '0';
        if(ma[x] > x) {
            for(int j = i; j < n; j++) {
                int y = s.at(j) - '0';
                if(ma[y] >= y) {
                    s.at(j) = ma[y] + '0';
                }
                else break;
            }
            break;
        }
    }
    cout << s << '\n';
}