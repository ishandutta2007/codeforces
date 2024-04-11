#include "bits/stdc++.h"

using namespace std;

int sa[207], sb[207];
string a, b;

void check()
{
    bool tod = 0, tsw = 0;
    for(char x='a'; x<='z'; x++)
    {
        if(sa[x] < sb[x])
        {
            puts("need tree");
            return;
        }
        if(sa[x] > sb[x])
            tod = 1;
    }
    int ta = 0, tb = 0;
    while(a[ta] && b[tb])
    {
        if(a[ta]==b[tb])
        {
            ta++;
            tb++;   
        }
        else
        {
            ta++;
        }
    }
    if(b[tb])
        tsw = 1;
    if(tsw && tod)
    {
        puts("both");
        return;
    }
    if(tod)
    {
        puts("automaton");
        return;
    }
    if(tsw)
    {
        puts("array");
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    for(int i=0; a[i]; i++)
        sa[a[i]]++;
    for(int i=0; b[i]; i++)
        sb[b[i]]++;
    check();
}