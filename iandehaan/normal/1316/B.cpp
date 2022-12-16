#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<char> in;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            in.push(c);
        }

        vector<pair<string, int>> pos;
        for (int i = 1; i <= n; i++) {

            queue<int> copy;
            for (int j = 0; j < n; j++) {
                copy.push(in.front());
                in.push(in.front());
                in.pop();
            }

            for (int j = 0; j < i-1; j++) {
                in.push(in.front());
                in.pop();
            }

            string yeet;
            for (int j = 0; j < n; j++) {
                yeet.push_back(in.front());
                in.push(in.front());
                in.pop();
            }

            for (int j = i-1; j < n; j++) {
                in.push(in.front());
                in.pop();
            }

            if (((i+n) % 2) == 0) {
                reverse(yeet.begin()+(n-i+1), yeet.end());
            }

            pos.push_back(make_pair(yeet, i));
            //cout << yeet << ' ' << i << endl;
        }


        sort(pos.begin(), pos.end());

        cout << pos[0].first << endl;
        cout << pos[0].second << endl;
    }
}