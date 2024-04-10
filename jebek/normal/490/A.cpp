#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,x;
vector<int>v[3];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        x--;
        v[x].push_back(i+1);
    }
    n=min(v[0].size(),min(v[1].size(),v[2].size()));
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<v[0][i]<<" "<<v[1][i]<<" "<<v[2][i]<<endl;
}