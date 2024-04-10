#include <iostream>
#include <iomanip>
#include <cstring>
#define dmax 13
using namespace std;

char a[dmax], b[dmax];
double rez, rr, p2;

void r(int a, int b, int s, int sf)
{
    if(a==b)
        {
            if (s==sf) rr++;
        }
    else
        {
            r(a+1, b, s+1, sf);
            r(a+1, b, s-1, sf);
        }
}

void solve()
{
    int k=0, l=0, w=0;
    for(int i=0;a[i]!=0;i++)
    {
        if(a[i]=='+')
            k++;
        else k--;
    }
    for(int i=0;b[i]!=0;i++)
    {
        if(b[i]=='+')
            k--;
        else if(b[i]=='-')
            k++;
        else if(b[i]=='?')
            w++;
    }
    p2=1<<w;
    r(0,w,0,k);

}

int main()
{

    cin>>a;
    cin>>b;

    solve();

    rez=rr/p2;
    cout<<fixed<<setprecision(10)<<rez<<'\n';
    return 0;
}