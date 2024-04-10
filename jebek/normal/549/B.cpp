#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n,a[200];
string s[200];
vector<int>ans;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<n;j++)
        for(int i=0;i<n;i++)
            if(a[i]==0)
            {
                ans.push_back(i+1);
                for(int x=0;x<n;x++)
                    if(s[i][x]=='1')
                        a[x]--;
            }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}