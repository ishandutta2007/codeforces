#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(n%2==0)
            cout<<(k-1)%n+1<<endl;
        else
        {
            int x=(k-1)/(n-1),y=(k-1)%(n-1);
            if(y>=n/2)
                y++;
            cout<<(x%n+y)%n+1<<endl;
        }
    }
    return 0;
}
//5 4 3 2 1 5 4 3 2 1
//1 2 4 5 2 3 5 1 3 4