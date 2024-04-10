#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
vector<int>a[11];
int main()
{

    ios::sync_with_stdio(0);
    int t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>s;
        for(int i=0;i<10;i++)a[i].clear();
        int ans=0;
        for(int i=0;i<s.size();i++)
            a[s[i]-'0'].push_back(i);
        for(int i=0;i<10;i++)
        {
            int z=a[i].size();
            ans=max(ans,z);
            for(int j=0;j<10;j++)
            {
                if(a[i].empty()||a[j].empty())continue;
                if(j==i)continue;
                int l=0,r=0,res=0;
                while(true){
                while(r<a[j].size()&&a[j][r]<a[i][l])r++;
                if(r==a[j].size())break;
                res+=2;
        ans=max(ans,res);
              while(l<a[i].size()&&a[i][l]<a[j][r])l++;
              if(l==a[i].size())break;}
  }

        }
        cout<<s.size()-ans<<endl;
    }
    return 0;
}