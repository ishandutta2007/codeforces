#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    string t = "";
    for(auto c : s) t += '0';
    t.pop_back();
    t += '1';
    int cnt = 0;
    int tren = s.size()-1;
    while(1){
        if(t < s){
            cnt++;
        }
        else break;
        t[tren] = '0';
        if(tren < 2) break;
        t[tren-2] = '1';
        tren -= 2;
    }
    cout << cnt;
    return 0;
}