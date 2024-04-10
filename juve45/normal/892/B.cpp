#include <bits/stdc++.h>

using namespace std;

int n,i, l[1000001],alive,current;
int main()
{
    cin>>n;
    alive=n;
    current=0;
    for (i=n;i>=1;i--)
        cin>>l[i];
    for (i=1;i<=n;i++)
    {
        if (current>0)
            alive--;
        if (current>0)
            current--;
        if (l[i]>current)
            current=l[i];
    }
    cout<<alive;
    return 0;
}