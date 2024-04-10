#include<bits/stdc++.h>
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
int n,m,k;
cin>>n>>m>>k;
string a,b;
cin>>a>>b;
sort(a.begin(),a.end());
sort(b.begin(),b.end());
string ans="";
int tmp[2]={0,0};
int i=0,j=0;
while(i<a.size()&&j<b.size())
{
    if(a[i]<b[j])
    {
        if(tmp[0]<k)
        {
            ans+=a[i];
            tmp[0]++;
            tmp[1]=0;
            i++;
            continue;
        }
        else
        {
            ans+=b[j];
            tmp[1]++;
            tmp[0]=0;
            j++;
            continue;
        }
    }
    if(b[j]<a[i])
    {
        if(tmp[1]<k)
        {
            ans+=b[j];
            tmp[1]++;
            tmp[0]=0;
            j++;
            continue;
        }
        else
            {
            ans+=a[i];
            tmp[0]++;
            tmp[1]=0;
            i++;
            continue;
        }
    }
}
cout<<ans<<endl;

}

return 0;
}