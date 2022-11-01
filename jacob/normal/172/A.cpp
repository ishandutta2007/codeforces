#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    string prev;
    cin >> prev;
    int res = (int)prev.size();
    for (int i = 1; i < n; ++i) {
        string cur;
        cin >> cur;
        int cp = 0;
        while (cur[cp] == prev[cp])
            ++cp;
        if (cp < res)
            res = cp;
        cur.swap(prev);
    }
    cout << res << endl;
    return 0;
}