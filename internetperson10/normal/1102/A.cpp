#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n%4==2 || n%4==1)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}