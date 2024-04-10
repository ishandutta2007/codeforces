#include <iostream>
#include<vector>

using namespace std;

vector<int>v[110];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2==0)
            {
                v[j].push_back(i*n+j);
            }
            else
                v[n-j+1].push_back(i*n+j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}