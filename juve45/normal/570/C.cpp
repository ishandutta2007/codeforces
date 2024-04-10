#include <iostream>

using namespace std;

int n, m;
char a[300009], c;
int lg, nr, pos;

int main()
{
    cin>>n>>m;

    a[0]=='0';

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]=='.')
        {
            lg++;
            if(a[i-1]!='.')
                nr++;
        }
    }
    a[n+1]=='n';
    for(int i=1; i<=m; i++)
    {
        cin>>pos>>c;
        if(c=='.')
        {
            if(a[pos]!='.')
            {
                lg++;
                if(a[pos-1]=='.' && a[pos+1]=='.')
                    nr--;
                else if(a[pos-1]!='.' && a[pos+1]!='.')
                    nr++;
            }
        }
        else
        {
            if(a[pos]=='.'){
                lg--;
                if(a[pos-1]=='.' && a[pos+1]=='.')nr++;
                if(a[pos-1]!='.' && a[pos+1]!='.')nr--;
            }
        }
        a[pos]=c;
        cout<<lg-nr<<'\n';
    }

    return 0;
}