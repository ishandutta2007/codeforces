#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int a=0; a<n; a++) {
        string s;
        cin >> s;
        switch(s.at(s.size()-1)) {
            case 'o':
                cout << "FILIPINO\n";
                break;
            case 'u':
                cout << "JAPANESE\n";
                break;
            default:
                cout << "KOREAN\n";
                break;
        }
    }
}