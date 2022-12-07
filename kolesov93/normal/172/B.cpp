#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define N 111111

int a, b, m;
int r;

int iter[N];

int main() {
    cin >> a >> b >> m >> r;
    
    int it = 1;
    do {
        iter[r] = it++;
        r = (r * a + b) % m;
    } while (!iter[r]);
    cout << it - iter[r] << endl;
        
    return 0;
}