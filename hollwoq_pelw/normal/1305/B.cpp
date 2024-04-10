#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = 0, r = s.length();
    vector <int> a,b;
    while(l < r){
        while(s[l] != '(' && l < s.length() && r >= 0) l++;
        while(s[r] != ')' && l < s.length() && r >= 0) r--;
        if (l < r) {a.push_back(l); b.push_back(r);}
        l++;
        r--;
    }
    if (!a.size() && !b.size()) return cout << 0, 0;
    cout << 1 << endl << a.size()+b.size() << endl;
    for (int i = 0; i < a.size(); i++) cout << a[i]+1 << ' ';
    for (int i = b.size()-1; i >= 0; i--) cout << b[i]+1 << ' ';
    return 0;
}