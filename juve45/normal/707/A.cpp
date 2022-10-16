#include <bits/stdc++.h>

using namespace std;
int n, m;
char a;
int main()
{
    cin>>n>>m;

    for(int i=1;i<=n*m;i++)
    {
        cin>>a;
        if(a!='G'&&a!='B'&&a!='W')
        {
            cout<<"#Color";
            return 0;
        }
    }
    cout<<"#Black&White";

    return 0;
}