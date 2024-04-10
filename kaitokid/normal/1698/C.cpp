#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;

        for(int i=0;i<n;i++)cin>>a[i];
        int u=0,v=0,q=0;
        for(int i=0;i<n;i++)
        {if(a[i]>0)u++;
        if(a[i]<0)v++;
        if(a[i]==0)q++;}

        if((u>3)||(v>3)){cout<<"NO"<<endl;continue;}
        vector<int>g;
        for(int i=0;i<n;i++)if(a[i]!=0)g.push_back(a[i]);
        for(int i=0;i<min(3,q);i++)g.push_back(0);
        bool bl=true;
        for(int i=0;i<g.size();i++)
            for(int j=i+1;j<g.size();j++)
                for(int k=j+1;k<g.size();k++)
                {
                    ll c=g[i];
                    c+=g[j];
                    c+=g[k];
                    bool h=false;
                    for(int d=0;d<g.size();d++)
                        if(c==g[d]){h=true;break;}
                   if(!h)bl=false;

                }
             if(bl)cout<<"YES"<<endl;
             else cout<<"NO"<<endl;
    }
    return 0;
}