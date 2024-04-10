#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, t;
    cin >> n >> t;
    
    vector<char> v;
    v.reserve(n + 1);
    v.push_back('0');
    int point = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '.') {
            point = i + 1;
        } else {
            v.push_back(c);
        }
    }



    // bool point_in_row = false;
    int row = 0;
    int m = numeric_limits<int>::max();

    for (int i = point; i < v.size(); i++) {
        if (v[i] == '4') {
            row++;
        } else if (v[i] < '4') {
            row = 0;
        } else {
            row = min(t-1, row);

            m = i - row;
            if (v[i-row] == '9')
            {
                int j = i - row;
                v[j]++;
                while (v[j] > '9') {
                    v[j-1]++;
                    v[j] = '0';
                    j--;
                }
            }
            else {
                v[i-row-1]++;
                int j = i - row - 1;
                while (v[j] > '9') {
                    v[j-1]++;
                    v[j] = '0';
                    j--;
                }
            }
            for (int j = i - row; j < v.size(); j++) {
                v[j] = '0';
            }
            break;
        }
    }

    if (v[0] > '0') {
        cout << v[0];
    }
    m = max(point, m);
    for (int i = 1; i < v.size(); i++) {
        if (i == m) break;
        if (i == point) 
            cout << '.';
        cout << v[i];
    }
    cout << endl;


    return 0;
}