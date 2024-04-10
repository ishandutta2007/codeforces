#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unsigned long long sum = 1;
    for(unsigned int i = 2; i <= n; i++)
    {
        sum *= i;
    }
    for(unsigned int i = 2; i <= n / 2; i++)
    {
        sum /= i;
        sum /= i;
    }
    sum /= 2;
    for(unsigned int i = 2; i <= n / 2 - 1; i++)
    {
        sum *= i;
        sum *= i;
    }
    cout << sum << endl;
}