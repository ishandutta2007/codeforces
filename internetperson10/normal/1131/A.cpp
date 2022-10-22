#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << 2*(h1+h2+max(w1, w2)+2);
}