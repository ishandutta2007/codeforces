#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <utility>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "2\n";
        } else if (n == 3) {
            cout << "3\n";
        } else {
            ll lowerBound = 4;
            while (n >= lowerBound) {
                lowerBound *= 4;
            }
            lowerBound /= 4;
            n -= lowerBound;
            ll pivot = lowerBound + n / 3;
            ll rem = n % 3;
            ll digitsCount = 0;
            ll lowerBoundCopy = lowerBound;
            while (lowerBoundCopy > 0) {
                digitsCount++;
                lowerBoundCopy /= 2;
            }
            vector<bool> binary(digitsCount + 1, false);
            int currIndex = 0;
            while (pivot > 0) {
                //cout << n << " " << pivot << " " << digitsCount << endl;
                if (pivot % 2 == 1) {
                    //cout << currIndex << endl;
                    binary[currIndex] = true;
                }
                currIndex++;
                pivot /= 2;
            }
            for (int index = digitsCount - 1; index >= 0; index -= 2) {
                if (rem == 1) {
                    if (binary[index] && !binary[index + 1]) {
                        binary[index] = false;
                        binary[index + 1] = true;
                    } else if (binary[index] && binary[index + 1]) {
                        binary[index] = true;
                        binary[index + 1] = false;
                    } else if (!binary[index] && binary[index + 1]) {
                        binary[index] = true;
                        binary[index + 1] = true;
                    }
                } else if (rem == 2) {
                    if (binary[index] && !binary[index + 1]) {
                        binary[index] = true;
                        binary[index + 1] = true;
                    } else if (binary[index] && binary[index + 1]) {
                        binary[index] = false;
                        binary[index + 1] = true;
                    } else if (!binary[index] && binary[index + 1]) {
                        binary[index] = true;
                        binary[index + 1] = false;
                    }
                }
            }

            ll result = 0;
            ll powerTwo = 1;
            for (int i = 0; i <= digitsCount; i++) {
                if (binary[i]) {
                    result += powerTwo;
                }
                powerTwo *= 2;
            }

            cout << result << "\n";
        }
    }
}