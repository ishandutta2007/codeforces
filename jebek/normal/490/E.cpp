#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n,f[20],a[200000];
string s[200000];
vector<int>v[200000];

int main()
{
    cin>>n;
    f[0]=1;
    for(int i=1;i<10;i++)
        f[i]=f[i-1]*10;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='?')
            {
                a[i]=a[i]*10+9;
                v[i].push_back(s[i].size()-j-1);
            }
            else
                a[i]=a[i]*10+int(s[i][j]-'0');
        }
    }
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=a[i-1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for(int j=0;j<v[i].size();j++)
        {
            int x=v[i][j];
            a[i]-=9*f[x];
            if(x==s[i].size()-1)
            {
                for(int u=1;u<=9;u++)
                    if(a[i]+u*f[x]>a[i-1])
                    {
                        a[i]+=u*f[x];
                        break;
                    }
            }
            else
            {
                for(int u=0;u<=9;u++)
                    if(a[i]+u*f[x]>a[i-1])
                    {
                        a[i]+=u*f[x];
                        break;
                    }
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
}