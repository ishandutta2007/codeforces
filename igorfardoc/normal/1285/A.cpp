#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int amountl = 0;
    int amountr = 0;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if(c == 'L')
        {
            amountl++;
        }
        else
        {
            amountr++;
        }
    }
    cout << amountl + amountr + 1;
}