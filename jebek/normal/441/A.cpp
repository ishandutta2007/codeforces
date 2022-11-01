#include <iostream>
#include<Algorithm>
#include<vector>

using namespace std;

long long n,v,a,t;
bool mark;
vector<int>ans;

int main()
{
    cin>>n>>v;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        mark=false;
        for(int j=0;j<t;j++)
        {
            cin>>a;
            if(v>a)
                mark=true;
        }
        if(mark)
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}