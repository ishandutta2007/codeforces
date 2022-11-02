#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,t;
    cin>>a>>t;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    while(t--)
    {
        int c,d,e,licz=0,f;
        cin>>c>>d>>e;
        f=tab[e];
        for(int x=c;x<=d;x++)
            if(tab[x]<f)
                licz++;
        if(licz==e-c)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<'\n';
    }
    return 0;
}