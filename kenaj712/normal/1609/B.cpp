#include<bits/stdc++.h>
using namespace std;
char tab[1000005];
int check(int x)
{
    int res = 0;
    for(int y=0;y<3;y++)
        if(tab[x-2+y] == 'a' && tab[x-1+y] == 'b' && tab[x+y] == 'c')
            res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,t;
    cin>>a>>t;
    for(int x=2;x<=a+1;x++)
        cin>>tab[x];
    int licz = 0;
    for(int x=2;x<=a-1;x++)
        if(tab[x] == 'a' && tab[x+1] == 'b' && tab[x+2] == 'c')
            licz++;
    while(t--)
    {
        int c;
        char d;
        cin>>c>>d;
        c++;
        licz -= check(c);
        tab[c] = d;
        licz += check(c);
        cout<<licz<<'\n';
    }
    return 0;
}