#include <bits/stdc++.h>
using namespace std;

enum Sign {
    BG = 1, SM = -1, EQ = 0
};

Sign ask(int c, int d) {
    cout << "? " << c << " " << d << endl;
    int resp;
    cin >> resp;
    return Sign(resp);
}

int main() {
    Sign rem = ask(0, 0);
    
    int pre_a = 0;
    int pre_b = 0;

    for (int i = 29; i >= 0; i--) {
        int zero = 0;
        int one = 1 << i;

        if (rem == EQ) {
            Sign ans = ask(pre_a + zero, pre_b + one);
            if (ans == SM) {
                pre_a += zero;
                pre_b += zero;
                rem = EQ;
            } else {
                pre_a += one;
                pre_b += one;
                rem = EQ;
            }
            continue;
        }

        if (rem == BG) {
            Sign ans = ask(pre_a + zero, pre_b + one);
            if (ans == BG) {
                Sign ans2 = ask(pre_a + one, pre_b + one);
                if (ans2 == BG) {
                    pre_a += one;
                    pre_b += one;
                    rem = BG;
                } else if (ans2 == SM) {
                    pre_a += one;
                    pre_b += zero;
                    rem = BG;
                } else {
                    assert(false);
                }
            } else if (ans == SM) {
                Sign ans2 = ask(pre_a + one, pre_b + one);
                if (ans2 == BG) {
                    pre_a += zero;
                    pre_b += zero;
                    rem = BG;
                } else if (ans2 == SM) {
                    pre_a += one;
                    pre_b += zero;
                    rem = SM;
                } else {
                    assert(false);
                }
            } else { // ans == EQ
                pre_a += one;
                pre_b += zero;
                rem = EQ;
            }
        } else {
            Sign ans = ask(pre_a + zero, pre_b + one);
            if (ans == SM) {
                Sign ans2 = ask(pre_a + one, pre_b + one);
                if (ans2 == SM) {
                    pre_a += zero;
                    pre_b += zero;
                    rem = SM;
                } else if (ans2 == BG) {
                    pre_a += zero;
                    pre_b += one;
                    rem = SM;
                } else {
                    assert(false);
                }
            } else if (ans == BG) {
                Sign ans2 = ask(pre_a + one, pre_b + one);
                if (ans2 == BG) {
                    pre_a += zero;
                    pre_b += one;
                    rem = BG;
                } else if (ans2 == SM) {
                    pre_a += one;
                    pre_b += one;
                    rem = SM;
                } else {
                    assert(false);
                }
            } else { // ans == EQ
                pre_a += zero;
                pre_b += one;
                rem = EQ;
            }
        }
    }

    cout << "! " << pre_a << " " << pre_b << endl;
}