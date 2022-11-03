#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 10000;

int main(){
    int n;
    cin >> n;
    int cur = mx;
    int a;
    string s;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(s == "North"){
            cur += a;
        }else if(s == "South"){
            cur -= a;
        }else if(abs(cur) == mx){
            cout << "NO" << endl;
            return 0;
        }
        if(abs(cur) > mx){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(cur != mx){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}