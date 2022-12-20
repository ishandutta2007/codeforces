#include <iostream>
#include <string>
using namespace std;

int main() {
    uint64_t cnts[3];
    // # of "vv"
    cnts[0] = 0;
    // # of "vv...o"
    cnts[1] = 0;
    // # of "vv..o..vv"
    cnts[2] = 0;
    string inp;
    cin >> inp;
    for (int i = 1; i < inp.size(); i++) {
        if (inp[i] == 'v' && inp[i-1] == 'v') {
            cnts[2] += cnts[1];
            cnts[0]++;
        } else if (inp[i] == 'o') {
            cnts[1] += cnts[0];
        }
    }
    cout << cnts[2] << endl;
}