#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    bool tren=0;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == 'a' && tren == 1) break;
        if(s[i] == 'a') continue;
        else{
            s[i]--;
            tren=1;
        }
    }
    if(tren == 0){
        s[n-1] = 'z';
        // cek korner kejses nub
    }
    cout << s;
    return 0;
}