#include <iostream>
#include <string>
using namespace std;

bool marked[200000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        string s;
        cin >> s;
        
        for (int i = 0; i < s.size(); i++) {
            marked[i] = false;
        }
        int out = 0;
        for (int i = 0; i < ((int)s.size())-2; i++) {
            if (marked[i]) continue;
            if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
                marked[i+1] = true;
                out++;
            }
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
                if (i < s.size() - 4 && s[i+3] == 'n' && s[i+4] == 'e') {
                    out++;
                    marked[i+2] = true;
                } else {
                    out++;
                    marked[i+1] = true;
                }
            }
        }
        cout << out << endl;
        for (int i = 0; i < s.size(); i++) {
            if (marked[i]) {
                cout << i+1 << ' ';
            }
        }
        cout << endl;
    }
}