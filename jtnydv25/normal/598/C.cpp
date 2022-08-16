#include <bits/stdc++.h>
using namespace std;
#define ld long double
const ld PI = acos(-1);
int main()
{
    int n,x,y;
    cin>>n;
    vector<pair<ld,int> > angs;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&x);scanf("%d",&y);
        ld ang = atan2(y,x);
        if(ang<0)
            ang+=2*PI;
        angs.push_back(make_pair(ang,i));
    }
    sort(angs.begin(),angs.end());
    ld cdiff = PI;
    int ind = 0;
    for(int i = 0;i<n;i++)
    {
        ld diff = abs(angs[(i+1)%n].first - angs[i].first);
        diff = min(diff,2*PI-diff);
        if(diff < cdiff)
        {
            cdiff = diff;
            ind = i;
        }
    }
    cout<<angs[ind].second <<" "<< angs[(ind+1)%n].second;
}