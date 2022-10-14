#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s.length()%2==1) {
            cout << "NO\n";
        } else {
            cout << (s[0]==')' or s.back()=='('?"NO":"YES") << endl;
        }
    }
}