#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> stuff[n];
        for (int i = 0; i < n; i++) cin >> stuff[i].first >> stuff[i].second;
        sort(stuff, stuff+n);

        int posx = 0;
        int posy = 0;
        vector<char> moves;
        bool good = true;
        for (int i = 0; i < n; i++) {
            while (stuff[i].first > posx) {
                posx++;
                moves.push_back('R');
            }
            while (stuff[i].second > posy) {
                posy++;
                moves.push_back('U');
            }

            if (posx != stuff[i].first || posy != stuff[i].second) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << "YES" << endl;
            for (char c : moves) {
                cout << c;
            } cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}