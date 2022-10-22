#include <iostream>

using namespace std;

int main() {
    int banana;
    cin >> banana;
    for(int a=0; a<banana; a++) {
        if(a%2==0)
            cout << "I hate ";
        else
            cout << "I love ";
        if(a<banana-1)
            cout << "that ";
        else
            cout << "it";
    }
}