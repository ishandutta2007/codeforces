#include<bits/stdc++.h>

using namespace std;

int t;
int c1, c2, c3;
int a1, a2, a3, a4, a5;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> c1 >> c2 >> c3;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        c1 -= a1;
        c2 -= a2;
        c3 -= a3;
        if(c1 < 0 || c2 < 0 || c3 < 0){
            cout << "No\n";
            continue;
        }
        a4 -= min(a4, c1);
        c3 -= a4;
        a5 -= min(a5, c2);
        c3 -= a5;
        if(c3 < 0){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}