#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        string s;
        cin >> s;
        int l = 0,r = s.length()-1;
        while(s[l] == '0' && l < r) l ++;
        while(s[r] == '0' && r > l) r --;
        if (l == r) {cout << 0 << endl; continue;}
        int c = 0;
        for (int i = l; i <= r; i++){
            c += (s[i] == '0');
        }
        cout << c << endl;
    }
    return 0;
}