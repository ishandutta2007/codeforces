#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ss(n);
        for (int i = 0; i < n; i++) cin >> ss[i];
        set<int> s;
        for (auto el : ss) s.insert(el);
        bool bigGame = true;
        for (int v = 1; v < 1024; v++) {
            set<int> newS;
            for (auto el : s) newS.insert(el ^ v);
            if (s == newS) {
                cout << v << "\n";
                bigGame = false;
                break;
            }
        }
        if (bigGame) {
            cout << "-1\n";
        }
    }
}