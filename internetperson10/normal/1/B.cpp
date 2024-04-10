#include <bits/stdc++.h>
#define ll long long

using namespace std;

int lton(string s) {
    int k = 0;
    for(int i = 0; i < s.size(); i++) {
        k *= 26;
        k += (int)(s.at(i)-'A'+1);
    }
    return k;
}
string ntol(int n) {
    string s = "";
    while(n) {
        n--;
        int m = n%26;
        n /= 26;
        m++;
        string es(1, (char)('A'+m-1));
        s.insert(0, es);
    }
    return s;
}
int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        bool rc = false, sad = false;
        cin >> s;
        if(s.at(0) == 'R') rc = true;
        if(rc) {
            for(int i = 1; i < s.size(); i++) {
                if(s.at(i) == 'C' && i > 1) {
                    if(!rc) sad = true;
                    rc = false;
                }
                else if(s.at(i) > '9') sad = true;
            }
            rc ^= true;
        }
        if(rc && !sad) {
            int row = 0, col = 0, i = 1;
            for(i; s.at(i) != 'C'; i++) {
                row *= 10;
                row += (int)(s.at(i)-'0');
            }
            i++;
            for(; i < s.size(); i++) {
                col *= 10;
                col += (int)(s.at(i)-'0');
            }
            cout << ntol(col) << row << '\n';
        }
        else {
            int i = 0;
            for(i; s.at(i) > '9'; i++) {
                
            }
            cout << 'R' << s.substr(i, s.size()-i) << 'C' << lton(s.substr(0, i)) << '\n';
        }
    }
}