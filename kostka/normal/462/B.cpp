//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int q[100];
vector <int> X;

int main()
{
    int n, k;
    cin >> n >> k;
    string x;
    cin >> x;
    for(int i=0; x[i]; i++)
        q[x[i]-'A']++;
    sort(q,q+26);
    long long wyn = 0;
    for(int i=25; i>=0; i--)
    {
        int r = min(q[i],k);
        wyn += 1LL*r*r;
        k -= r;
    }
    cout << wyn;
    return 0;
}