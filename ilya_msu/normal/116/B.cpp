#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool check(const vector<vector<char> >& data, int i, int j) {
    if (data[i][j] != 'W')
        return false;
    if ((i > 0) && (data[i - 1][j] == 'P'))
        return true;
    if ((j > 0) && (data[i][j - 1] == 'P'))
        return true;
    if ((i < data.size() - 1) && (data[i + 1][j] == 'P'))
        return true;
    if ((j < data[i].size() - 1) && (data[i][j + 1] == 'P'))
        return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > data(n, vector<char> (m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> data[i][j];
    int x = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            if (check(data, i, j))
                ++x;
    cout << x << endl;
    return 0;
}