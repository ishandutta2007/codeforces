#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int c=0;
    cin >> s;
    for (char & t : s){
        if (t == '4' || t == '7') c++;
    }
    if (c == 4 || c == 7) cout << "YES";
    else cout << "NO";
    return 0;
}