#include <bits/stdc++.h>

using namespace std;

int summ(int a){
    int c[10];
    c[0] = 6;
    c[1] = 2;
    c[2] = 5;
    c[3] = 5;
    c[4] = 4;
    c[5] = 5;
    c[6] = 6;
    c[7] = 3;
    c[8] = 7;
    c[9] = 6;
    int kol = 0;
    int i = a;
    while(i > 9){
        kol += c[i % 10];
        i = i / 10;
    }
    kol += c[i];
    return kol;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int tek = 0;
    for(int i = a; i <= b; i++){
        tek += summ(i);
    }
    cout << tek;
}