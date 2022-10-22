#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,bool>mp;
string s[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            mp[s[i]]=true;
        }
        for(int i=0;i<n;i++)
        {
            bool bl=false;
            for(int j=0;j+1<s[i].size();j++)
            {
                string u="",v="";
                for(int q=0;q<=j;q++)u+=s[i][q];
                for(int q=j+1;q<s[i].size();q++)v+=s[i][q];
                if(mp[u]&&mp[v]){bl=true;break;}
            }
            if(bl)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;

}