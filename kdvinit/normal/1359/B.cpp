#include <iostream>
using namespace std;

void solve()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int total=0,cntr1=0,cntr2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char v;
            cin>>v;
            if(v=='*') cntr2=0;
            else
            {
                total++;
                if(cntr2==1) { cntr1++; cntr2=0;}
                else cntr2=1;
            }
        }
        cntr2=0;
    }
    //cout<<total<<" "<<cntr1<<endl;
    long long int ans1=total*x,ans2=(total-(2*cntr1))*x+cntr1*y;
    cout<<min(ans1,ans2)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}