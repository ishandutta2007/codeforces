#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int cn1, cn2, cn3, cn4;
    cin >> cn1 >> cn2 >> cn3 >> cn4;
    if(cn3) {
        if(cn1+cn4 && (cn1==cn4))
            cout << 1;
        else cout << 0;
    }
    else {
        if(cn1==cn4)
            cout << 1;
        else cout << 0;
    }
}