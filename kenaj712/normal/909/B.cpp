#include<bits/stdc++.h>
using namespace std;
int tab[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        for(int y=x;y<a;y++)
            for(int z=x;z<=y;z++)
                tab[z]++;
    }
    int maks=0;
    for(int x=0;x<a;x++)
        maks=max(maks,tab[x]);
    cout<<maks;
    return 0;
}