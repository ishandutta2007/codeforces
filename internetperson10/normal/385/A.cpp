#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int d, p, maximum, b, s;
    cin >> d >> p >> s;
    maximum=p;
    for(int a=1; a<d; a++) {
        b=s;
        cin >> s;
        maximum=max(maximum, b-s);
    }
    cout << maximum-p;
}