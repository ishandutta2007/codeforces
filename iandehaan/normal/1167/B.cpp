#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int poss[6];
    poss[0] = 4;
    poss[1] = 8;
    poss[2] = 15;
    poss[3] = 16;
    poss[4] = 23;
    poss[5] = 42;
    
    int out[4];
    for (int i = 0; i < 4; i++) {
        cout << "? " << 1 << ' ' << i+2 << endl;
        fflush(stdout);
        cin >> out[i];
    }

    int first = 0;
    for (int i = 5; i >= 0; i--) {
        bool good = true;
        for (int j = 0; j < 4; j++) {
            if (out[j] % poss[i] != 0) {
                good = false;
                break;
            }
        }
        if (good) {
            first = poss[i];
            break;
        }
    }

    int yeet[6];
    yeet[0] = first;
    for (int i = 1; i < 5; i++) {
        yeet[i] = out[i-1]/yeet[0];
    }

    for (int i = 0; i < 6; i++) {
        bool good = true;
        for (int j = 0; j < 5; j++) {
            if (poss[i] == yeet[j]) {
                good = false;
                break;
            }
        }
        if (good) {
            yeet[5] = poss[i];
            break;
        }
    }
    cout << '!';
    for (int i = 0; i < 6; i++) {
        cout << ' ' << yeet[i];
    }
    cout << endl;
    fflush(stdout);
}