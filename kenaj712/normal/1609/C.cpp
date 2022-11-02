#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
bool prime(int a)
{
    for(int x=2;x*x<=a;x++)
        if(a%x==0)
            return false;
    return true;
}

void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    long long res = 0;
    for(int x=1;x<=b;x++)
    {
        long long last = 0;
        bool dodawaj = false;
        int ile_dodaj = 0;
        for(int y=x;y<=a;y+=b)
        {
            if(tab[y] == 1)
            {
                last ++;
                if(dodawaj)
                    res += ile_dodaj;
            }

            else if(prime(tab[y]))
            {
                dodawaj = true;
                ile_dodaj = last + 1;
                last = 0;
                res += ile_dodaj - 1;
            }
            else
            {
                last = 0;
                dodawaj = false;
            }
        }
    }
    cout<<res<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}