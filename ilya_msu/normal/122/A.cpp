#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;
    bool c = false;
    for (int i = 1; i <=n; ++i) {
        if (n % i == 0) {
            bool c1 = true;
            int j = i;
            while (j > 0) {
                int x = j % 10;
                c1 = c1 && ((x == 4) || (x == 7));
                j /= 10;
            }
            if (c1)
                c = true;
        }
    }
    if (c)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}