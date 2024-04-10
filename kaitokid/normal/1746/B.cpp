#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        vector<int>a,b;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x==0)a.push_back(i);
             else b.push_back(i);
        }
        int ans=0;
        int j=0;
       while((!a.empty())&&(j<b.size())&&(a.back()>b[j]))
       {
           a.pop_back();
           j++;
           ans++;
       }
       cout<<ans<<endl;
    }
    return 0;
}