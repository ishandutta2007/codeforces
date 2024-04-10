#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    bool s[10];
    bool p[10];
    bool m[10];
    for (int i = 0; i < 10; i++) {
        s[i] = false;
        p[i] = false;
        m[i] = false;
    }

    int int1, int2, int3;
    char suit1, suit2, suit3;
    cin >> int1 >> suit1 >> int2 >> suit2 >> int3 >> suit3;
    if (suit1 == suit2 && suit2 == suit3 && int1 == int2 && int2 == int3) {
        cout << 0 << endl;
        return 0;
    }
    int ints[3];
    ints[0] = int1;
    ints[1] = int2;
    ints[2] = int3;
    sort(ints, ints+3);
    if (suit1 == suit2 && suit2 == suit3 && ints[0] == ints[1]-1 && ints[1] == ints[2]-1) {
        cout << 0 << endl;
        return 0;
    }

    // 2 tiles are equal
    if (suit1 == suit2 && int1 == int2) {
        cout << 1 << endl;
        return 0;
    }
    if (suit2 == suit3 && int2 == int3) {
        cout << 1 << endl;
        return 0;
    }
    if (suit1 == suit3 && int1 == int3) {
        cout << 1 << endl;
        return 0;
    }
    // 2 tiles are in order
    if (suit1 == suit2 && (abs(int1-int2) == 1 || abs(int1-int2) == 2)) {
        cout << 1 << endl;
        return 0;
    }
    if (suit2 == suit3 && (abs(int2-int3) == 1 || abs(int2-int3) == 2)) {
        cout << 1 << endl;
        return 0;
    }
    if (suit1 == suit3 && (abs(int1-int3) == 1 || abs(int1-int3) == 2)) {
        cout << 1 << endl;
        return 0;
    }
    cout << 2 << endl;
}