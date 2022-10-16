#include <bits/stdc++.h>

#define DMAX 120
#define x first
#define y second

int n;
char a[DMAX];
using namespace std;

int main()
{

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j+4*i<=n; j++)
        {
            if(a[j]=='*' && a[j+i]=='*' && a[j+4*i]=='*' && a[j+2*i]=='*' && a[j+3*i]=='*')
            {
                cout<<"yes\n";
                return 0;
            }
        }

    cout<<"no\n";
    return 0;

}