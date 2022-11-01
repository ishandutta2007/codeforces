#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;
ll n,m,ans[200][200],MAX,a[200];
set<ll>s;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>ans[i][j];
            MAX=max(MAX,ans[i][j]);
        }
    MAX++;
    for(int i=0;i<n;i++)
        a[i]=ans[i][0];
    for(int i=0;i<n && s.size()<2;i++)
        for(int j=0;j<n && s.size()<2;j++)
            if(i!=j && a[i]<=a[j])
                for(int x=1;x<m && s.size()<2;x++)
                {
                    if(ans[i][x]<=ans[j][x])
                    {
                        if(ans[j][x]-ans[i][x]!=a[j]-a[i])
                        {
                            cout<<"NO"<<endl;
                            return 0;
                        }
                    }
                    else
                    {
                        if(a[j]-a[i]-ans[j][x]+ans[i][x]<MAX)
                        {
                            cout<<"NO"<<endl;
                            return 0;
                        }
                        s.insert(a[j]-a[i]-ans[j][x]+ans[i][x]);
                    }
                }
    if(s.size()>1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(s.size()==1)
        MAX=*(s.begin());
    cout<<"YES"<<endl<<MAX<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)
        cout<<(ans[0][i]-a[0]+MAX)%MAX<<" ";
    cout<<endl;
}