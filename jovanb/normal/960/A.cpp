#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    
    string str;
    cin >> str;
    bool biob = false;
    bool bioc = false;
    int bra = 0, brb=0, brc=0;
    int n = str.size();
    for(int i=0; i<n; i++){
        if(str[i] == 'a'){
            if(biob || bioc){cout << "NO"; return 0;}
            bra++;
        }
        else if(str[i] == 'b'){
            if(bioc){cout << "NO"; return 0;}
            brb++;
            biob = 1;
        }
        else{
            bioc = 1;
            brc++;
        }
    }
    if(bra == 0 || brb == 0) cout << "NO";
    else if(brc != bra && brc != brb) cout << "NO";
    else cout << "YES";
    return 0;
}