#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        string s;
        cin >> s;
        string a = s.substr(s.length()-2);
        if (a == "po") cout << "FILIPINO" << endl;
        if (a == "su") cout << "JAPANESE" << endl;
        if (a == "da") cout << "KOREAN" << endl;
    }
    return 0;
}