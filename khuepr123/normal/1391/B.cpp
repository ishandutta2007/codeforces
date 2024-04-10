#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; int n, m; int a[101][101]; char c; int sum;
    for(int o = 0; o < t; o++){
        sum = 0;
        cin >> n >> m;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= m; j++){
                cin >> c;
            }
            if(c - 114 == 0 || c - 82 == 0){
                sum = sum + 1;
            }
        }
        for(int j = 1; j < m; j++){
            cin >> c;
            if(c - 68 == 0||c - 100 == 0){
                sum = sum + 1;
            }
        }
        cin >> c;
        cout << sum << "\n";
    }
}