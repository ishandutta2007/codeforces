#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
     vector < pair<int,int> > a,b;
    int ans=0,besta=1e9,bestb=1e9;
    char t[8][8];
    for (int i=0;i<8;i++)
    for (int j=0;j<8;j++)
    {
        cin >>t[i][j];
        if (t[i][j]=='W')
            a.push_back(make_pair(i,j));
        if (t[i][j]=='B')
            b.push_back(make_pair(i,j));
    }

    for (size_t i=0;i<a.size();i++)
    {
        int ti=a[i].first;
        int tj=a[i].second;
        char mozhet='Y';
        for (int k=ti;k>=0;k--)
        {
            if (t[k][tj]!='.'&&k!=ti)
            {mozhet='N'; break;
            }
        }
        if (mozhet=='Y')
         besta=min(besta,ti);
    }
   for (size_t i=0;i<b.size();i++)
    {
        int ti=b[i].first;
        int tj=b[i].second;
        char mozhet='Y';
        for (int k=ti;k<=7;k++)
        {
            if (t[k][tj]!='.'&&k!=ti)
            {mozhet='N'; break;
            }
        }
        if (mozhet=='Y')
         bestb=min(bestb,7-ti);
    }

    if (besta<=bestb)
        cout<<'A';
    else cout<<'B';
    return 0;
}