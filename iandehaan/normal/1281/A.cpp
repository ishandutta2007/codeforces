#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        string inp;
        cin >> inp;
        int n = inp.size();
        if (inp[n-1] == 'o' && inp[n-2] == 'p') {
            cout << "FILIPINO" << endl;
        } else if (inp.size() >= 5 && inp[n-1] == 'a' && inp[n-2] == 'd' && inp[n-3] == 'i' && inp[n-4] == 'n' && inp[n-5] == 'm') {
            cout << "KOREAN" << endl;
        } else {
            cout << "JAPANESE" << endl;
        }
    }
}