#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string p, h;
        cin >> p >> h;


        bool yeet = false;
        for (int i = 0; i < (int)h.size()-(int)p.size()+1; i++) {
            int remaining[26];
            for (int i = 0; i < 26; i++) {
                remaining[i] = 0;
            }
            for (char c : p) {
                remaining[c-'a']++;
            }
            for (int j = i; j < i + p.size(); j++) {
                remaining[h[j]-'a']--; 
            }

            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (remaining[i]) good = false;
            }
            if (good) {
                cout << "YES" << endl;
                yeet = true;
                break;
            }
        }
        if (!yeet) cout << "NO" << endl;
    }
}