#include <iostream>

using namespace std;

char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    int testcases, strlen, alplen;
    cin >> testcases;
    for(int a=0; a<testcases; a++) {
        cin >> strlen >> alplen;
        for(int b=strlen; b>0; b--) {
            cout << alphabet[b%alplen];
        }
        cout << '\n';
    }
}