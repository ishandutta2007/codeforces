#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(b - a) + x) << endl;
    }
}