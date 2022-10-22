#include <bits/stdc++.h>
using namespace std;

int a[100005];
int da[100005];
int b[100005];
int db[100005];

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        da[i] = a[i] - a[i-1];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        db[i] = b[i] - b[i-1];
    }
    sort(da+2, da+1+n);
    sort(db+2, db+1+n);
    if(a[1] != b[1] || a[n] != b[n]){
        cout << "No";
        return 0;
    }
    for(int i=2; i<=n; i++){
        if(da[i] != db[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}