#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_map<int, int> bigboy;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int num = 0;
            while (x % 2 == 0) {
                x /= 2;
                num++;
            }
            if (bigboy.find(x) == bigboy.end()) {
                bigboy[x] = num;
            }
            bigboy[x] = max(bigboy[x], num);
        }
        int out = 0;
        for (pair<int, int> key : bigboy) {
            out += key.second;
        }
        cout << out << endl;
    }
}