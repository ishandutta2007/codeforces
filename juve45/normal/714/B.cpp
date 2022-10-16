#include <bits/stdc++.h>
#define DMAX 1000000
using namespace std;

map<int, int> m;
int t;
int x;
int a[5];
int main()
{
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        cin>>x;
        m[x]++;
    }
    if(m.size()>3)
    {
        cout<<"NO\n";
    }
    else
    {
        if(m.size()<=2)
            cout<<"YES\n";
                else
            {
                int i=0;
                for(map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
                {
                    a[++i]=it->first;
                }
                sort(a+1, a+4);
                if(a[2]-a[1]==a[3]-a[2])
                    cout<<"YES\n";
                else cout<<"NO"<<'\n';
            }
    }


    return 0;
}