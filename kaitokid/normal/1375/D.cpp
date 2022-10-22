#include <bits/stdc++.h>

using namespace std;
int t,n;
set<int>mex,nt;
int a[1008],num[1009];
vector<int>ans;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        ans.clear();
        cin>>n;
        for(int i=0;i<=n;i++)num[i]=0;
        for(int i=0;i<n;i++){mex.insert(i);nt.insert(i);}
        mex.insert(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mex.erase(a[i]);
            num[a[i]]++;
        }
        while(!nt.empty())
        {
            int u=(*mex.begin());
           // cout<<u<<endl;
            if(u==n)
            {
                int d=(*nt.begin());
                num[a[d]]--;
                if(num[a[d]]==0)
                mex.insert(a[d]);
                mex.erase(n);
                num[n]++;
                ans.push_back(d);
                a[d]=n;
            u=(*mex.begin());
            }
            ans.push_back(u);
            num[a[u]]--;
            if(num[a[u]]==0)
            mex.insert(a[u]);
            mex.erase(u);
            a[u]=u;
            num[u]++;
            nt.erase(u);
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)cout<<ans[i]+1<<" ";
        cout<<endl;
    }
    return 0;
}