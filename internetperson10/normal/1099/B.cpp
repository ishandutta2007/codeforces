#include <iostream>

using namespace std;

int main() {
    int n, a=0, b=1, c=0;
    cin >> n;
    while(n>a*b) {
        if(c%2==0)
            a++;
        else
            b++;
        c++;
    }
    cout << a+b << '\n';
}