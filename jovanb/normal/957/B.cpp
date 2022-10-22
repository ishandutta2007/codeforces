#include <bits/stdc++.h>
using namespace std;

string str[100];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=0; k<m; k++){
                if(str[i][k] == '#' && str[j][k] == '#'){
                    for(int x=0; x<m; x++){
                        if(str[i][x] != str[j][x]){cout << "No"; return 0;}
                    }
                    break;
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}