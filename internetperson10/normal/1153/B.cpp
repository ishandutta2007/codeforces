#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;

int main() {
    int n, m, h, k;
    cin >> n >> m >> h;
    for(int a=0; a<n; a++) {
        arr.push_back(vector<int>());
        for(int b=0; b<m; b++) {
            arr[a].push_back(h);
        }
    }
    for(int a=0; a<m; a++) {
        cin >> k;
        for(int b=0; b<n; b++) {
            arr[b][a]=min(arr[b][a], k);
        }
    }
    for(int a=0; a<n; a++) {
        cin >> k;
        for(int b=0; b<m; b++) {
            arr[a][b]=min(arr[a][b], k);
        }
    }
    for(int a=0; a<n; a++) {
        for(int b=0; b<m; b++) {
            cin >> k;
            cout << arr[a][b]*k << ' ';
        }
        cout << '\n';
    }
}