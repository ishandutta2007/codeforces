#include <bits/stdc++.h>

using namespace std;







int n,x,y,m,t,a[500001];
int main()
{

    ios_base::sync_with_stdio(false);

cin>>t;
while(t--)
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
     {

       for(int j=0;j<m;j++)
    {
        if(i==0&&j==0)cout<<'W';
        else cout<<'B';
    }
    cout<<endl;
     }

}








    return 0;
}