#include <iostream>

using namespace std;
pair< int ,int> z[10002];
int main()
{
    int x,y,a,b,res=0;
    cin>>x>>y>>a>>b;
    for(int i=a;i<=x;i++)
    {
        for(int j=b;j<=y;j++)
        {if(i>j){z[res]=make_pair(i,j);res++;}

        }
    }
    cout<<res<<endl;
    for(int i=0;i<res;i++)
    {
        cout<<z[i].first<<" "<<z[i].second<<endl;
    }
    return 0;
}