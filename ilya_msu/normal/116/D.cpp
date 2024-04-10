#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;



int main() {
    int n, m, maxN = 1;
    char c;
    cin >> n >> m;
    vector<int> mini(n + 2, m);
    mini[1] = 1;
    vector<int> maxi(n + 2, 0);
    maxi[1] = 1;
    for (int i = 1; i < n + 1; ++i) {
        for (int  j = 0; j < m; ++j) {
            cin >> c;
            if (c == 'W') {
                maxN = i;
                maxi[i] = j + 1;
                if (mini[i] == m)
                    mini[i] = j + 1;
            }
        }
        if (maxi[i] == 0)
                if (i % 2 == 0) {
                    maxi[i] = mini[i] = maxi[i - 1];
                }
                else
                    maxi[i] = mini[i] = mini[i - 1];
    }
    int x = 0;
    vector<int> data(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        if (i % 2 == 0) 
            data[i] = min(mini[i], mini[i + 1]);
        else
            data[i] = max(maxi[i], maxi[i + 1]);
    }
    for (int i = 1; i < n + 1; ++i) {
        if (i % 2 == 1)
            x += max(data[i] - data[i - 1], 0);
        else
            x += max(data[i - 1] - data[i], 0);
    }
    x += maxN - 1;
    cout << x << endl;
    return 0;
}