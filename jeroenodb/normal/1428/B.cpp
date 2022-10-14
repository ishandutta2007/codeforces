#include <iostream>
#include <string>
#include <bitset>
using namespace std;
const int mxN = 3e5;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool circular = true;
        bitset<mxN> can;
        char type = '-';
        for(int i=0;i<n;++i) { 
            char c = s[i];
            if(c=='-') {
                can[i]=true;
                can[(i+1)%n]=true;
                continue;
            }
            else if(c==type) continue;
            if(type=='-') {
                type = c;
            } else {
                circular = false;
            }
        }
        if(circular) {
            cout << n << endl;
        } else {
            cout << can.count() << endl;
        }
    }
}