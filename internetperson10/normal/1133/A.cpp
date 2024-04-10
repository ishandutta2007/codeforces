#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    int t=((h1+h2)*60+m1+m2)/2;
    int hj=t/60;
    int mj=t%60;
    if(hj<10)
        cout << "0";
    cout << hj << ":";
    if(mj<10)
        cout << "0";
    cout << mj;
}