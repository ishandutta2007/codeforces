#include <iostream>

using namespace std;

int gcf(int a, int b) {
    while(a!=b) {
        if(a>b)
            a-=b;
        if(b>a)
            b-=a;
    }
    return a;
}
int main() {
    int testcases, ang;
    cin >> testcases;
    for(int a=0; a<testcases; a++) {
        cin >> ang;
        if(gcf(180,(180-ang))==180-ang)
            cout << 2*(180/(gcf(180, ang))) << '\n';
        else
            cout << 180/(gcf(180, ang)) << '\n';
    }
}