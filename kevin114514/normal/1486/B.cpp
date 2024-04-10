#include<bits/stdc++.h>
using namespace std;
vector<long long> vx,vy;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vx.clear();
        vy.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            long long x,y;
            cin>>x>>y;
            vx.push_back(x);
            vy.push_back(y);
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        if(n%2)
        {
            puts("1");
        }
        else
        {
            cout<<(vx[n/2]-vx[n/2-1]+1)*(vy[n/2]-vy[n/2-1]+1)<<endl;
        }
    }
    return 0;
}