#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ima[1005][1005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, a, b;
    cin >> n >> a >> b;
    if(a > 1 && b > 1){
        cout << "NO";
        return 0;
    }
    if(a==1 && b==1){
        if(n == 3 || n == 2){cout << "NO"; return 0;}
        cout << "YES\n";
        for(int i=1; i<n; i++){
            ima[i][i+1] = 1;
            ima[i+1][i] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << ima[i][j];
            }
            cout << "\n";
        }
        return 0;
    }
    cout << "YES\n";
    bool swapovan = 0;
    if(a < b){swap(a, b); swapovan = true;}
    int bre = n-a;
    for(int i=1; i<n; i++){
        if(bre <= 0) break;
        bre--;
        ima[i][i+1] = 1;
        ima[i+1][i] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (i == j) cout << 0;
            else if(swapovan) cout << 1-ima[i][j];
            else cout << ima[i][j];
        }
        cout << "\n";
    }
    return 0;
}