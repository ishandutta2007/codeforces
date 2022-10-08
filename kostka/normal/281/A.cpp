#include "bits/stdc++.h"

using namespace std;

int main()
{
    string x;
    cin >> x;
    if('a'<=x[0] && x[0]<='z')
        x[0] = x[0]-'a'+'A';
    cout << x;
    return 0;
}