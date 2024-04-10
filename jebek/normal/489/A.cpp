#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
int n,a[10000],b[10000];
vector<pii>ans,v;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        v.push_back(pii(a[i],i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        b[i]=i;
    for(int i=0;i<n;i++)
        if(b[i]!=v[i].second)
        {
            for(int j=0;j<n;j++)
                if(b[j]==v[i].second)
                {
                    ans.push_back(pii(i,j));
                    swap(b[i],b[j]);
                    break;
                }
        }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}