#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define dmax 200004
using namespace std;
vector <int> a, b;
int la, lb, x, o,n;
long long  suma, sumb;
int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        o=0;
        cin>>x;
        if(x<0)
            x=-x, o=1;
        if(o==0)
            a.pb(x), suma+=a[la], la++;
        else
            b.pb(x), sumb+=b[lb], lb++;
    }


    if(suma>sumb)
        cout<<"first\n";
    if(sumb>suma)
        cout<<"second\n";
    if(sumb==suma)
    {
        if(a>b)
            cout<<"first\n";
        else if(b>a)
            cout<<"second\n";
        else
        {
            if(o==0)
                cout<<"first\n";
            else
                cout<<"second\n";
        }

    }


    return 0;
}