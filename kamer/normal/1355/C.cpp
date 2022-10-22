#include <iostream>
#include <algorithm>
using namespace std;

long long computeDiagonal(long long A, long long B, long long C, long long D, long long d) {
    long long res = 1 + d;
    if (d > (B - A)) {
        res = res - (d - B + A);
    }
    if (d > (D - C)) {
        res = res - (d - D + C);
    }
    return res;
}

int main(void) {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long n = 0;
    long long currZ = C;
    long long toAdd = (B - A + 1) * (C - B + 1);
    long long d = 0;
    long long result = 0;
    while (A + B + d <= currZ) {
        toAdd -= computeDiagonal(A, B, B, C, d);
        d++;
    }
    while (currZ <= D && (currZ < A + B + d - 1)) {
        result += toAdd;
        currZ++;
    }
    if (currZ > D) {
        cout << result << "\n";
        return 0;
    }
    result += toAdd;

    while (currZ < D && (A + B + d < B + C)) {
      toAdd -= computeDiagonal(A, B, B, C, d);
      result += toAdd;
      currZ++;
      d++;

    }
    cout << result << "\n";
    return 0;
}