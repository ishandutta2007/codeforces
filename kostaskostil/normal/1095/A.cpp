#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int n;
int a[300500];

main()
{
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    int j=0;
    while (i<n)
    {
        cout<<s[i];
        j++;
        i+=j;
    }
    return 0;
}