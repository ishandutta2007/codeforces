#include <bits/stdc++.h>

using namespace std;
char niz[100];
int main()
{
    int i, j, n, t;
    cin >> n >> t;
    cin >> niz;
    for (j=0; j<t; j++)
        for (i=0; i<n-1; i++){
            if (niz[i] < niz[i+1]) {
                niz[i+1] = 'B';
                niz[i] = 'G';
                i++;
            }
        }
    for (i=0; i<n; i++) {
        cout << niz[i];
    }
    return 0;
}