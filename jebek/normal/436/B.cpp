#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,ans[3000],x,k;
char c;

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>c;
            if(c=='U' && i%2==0)
            {
                ans[j]++;
               // cout<<i<<endl;
            }
            if(c=='L')
            {
                x=j-i;
               // cout<<x<<endl;
                if(x>-1)
                    ans[x]++;
            }
            if(c=='R')
            {
                x=j+i;
              //  cout<<x<<endl;
                if(x<m)
                    ans[x]++;
            }
        }
    for(int i=0;i<m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}