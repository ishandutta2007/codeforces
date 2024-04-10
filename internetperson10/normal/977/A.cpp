#include <iostream>

using namespace std;

int main() {
    int orig, opnum;
    cin >> orig >> opnum;
    for(int a=0; a<opnum; a++) {
        if(orig%10==0)
            orig/=10;
        else
            orig-=1;
    }
    cout << orig;
}