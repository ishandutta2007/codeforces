#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << (s[0]-'1')*10+(s.length()+1)*s.length()/2 << endl;
        
    }
}