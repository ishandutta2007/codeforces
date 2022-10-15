#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;


long long next (long long x) {
    if (x == 0)
        return 0;
    if (x % 10 <= 4)
        return next(x / 10) * 10 + 4;
    if (x % 10 <= 7)
        return next(x / 10) * 10 + 7;
    return next((x + 10 - (x % 10)) / 10) * 10 + 4; 
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> data(n + 1);
    data[n] = 0;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        data[i] = (int)(c - '0');
    }
    int state = 0;
    int change = -1;
    for (int i = 0; (i < n) && (k > 0); ++i) {
        if ((data[i] == 4) && (data[i + 1] == 7)) {
            if (i % 2 == 0) {
                data[i + 1] = 4;
                if (i + 1 == change)
                    k = min(k, k % 2 + 2);
                change = i + 1;
            }
            else {
                data[i] = 7;
                if (i == change)
                    k = min(k, k % 2 + 2);
                change = i;
            }
            --k;
            i -= 2;
            if (i < 0)
                i = -1;
            }

    }
    for (int i = 0; i < n; ++i)
        cout << data[i];
    cout << endl;
    
    return 0;
}