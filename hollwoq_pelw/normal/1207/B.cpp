#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int m,n;
    cin >> m >> n;
    int A[m][n], B[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
            B[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (A[i][j]){
                bool t = 0;
                if (i < m-1 && j < n-1){
                    t = t or (A[i][j] && A[i][j+1] && A[i+1][j] && A[i+1][j+1]);
                }
                if (i < m-1 && j > 0){
                    t = t or (A[i][j-1] && A[i][j] && A[i+1][j-1] && A[i+1][j]);
                }
                if (i > 0 && j < n-1){
                    t = t or (A[i-1][j] && A[i-1][j+1] && A[i][j] && A[i][j+1]);
                }
                if (i > 0 && j > 0){
                    t = t or (A[i-1][j-1] && A[i-1][j] && A[i][j-1] && A[i][j]);
                }
                if (!t){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    vector <pair<int,int>> a;
    int k = 0;
    for (int i = 0; i < m-1; i++){
        for (int j = 0; j < n-1; j++){
            if (A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]){
                k++;
                pair<int,int> x = make_pair(i+1,j+1);
                a.push_back(x);
            }
        }
    }
    cout << k << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
}