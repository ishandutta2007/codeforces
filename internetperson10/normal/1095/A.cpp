#include <iostream>
#include <string>

using namespace std;

int main () {
    int length, pick=0;
    string repeating;
    cin >> length >> repeating;
    for(int a=1; pick!=length; a++) {
        cout << repeating.at(pick);
        pick+=a;
    }
    return 0;
}