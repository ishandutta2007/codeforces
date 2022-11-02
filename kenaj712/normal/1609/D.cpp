#include<bits/stdc++.h>
using namespace std;
int lider[1000005];
int licz[1000005];
int lulz;
int f(int a)
{
    if(lider[a] != a)
        lider[a] = f(lider[a]);
    return lider[a];
}
void u(int a,int b)
{
    if(f(a) == f(b))
        lulz++;
    lider[f(a)] = f(b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        lider[x] = x;
    while(b--)
    {
        int c,d;
        cin>>c>>d;
        u(c,d);
        for(int x=1;x<=a;x++)
            licz[f(x)]++;
        sort(licz+1,licz+a+1);
        int maks = 0;
        for(int x=a;x>=a-lulz;x--)
        {
            maks += licz[x];
        }
        for(int x=1;x<=a;x++)
            licz[x] = 0;
        cout<<maks - 1<<'\n';
    }
    return 0;
}