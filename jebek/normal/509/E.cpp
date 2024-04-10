#include <iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

string s;
long double a,sum[1000000],ans;
vector<int>v;
int n;

void ok(int x)
{
   // cout<<x<<endl;
    a+=sum[n-x]-sum[x];
}

int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
            v.push_back(min(i,n-i-1));
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+((long double)1/(long double)i);
  //  cout<<sum[i]<<endl;
    }
    int x=0;
    a=sum[n];
    for(int i=0;i<v.size();i++)
    {
        while(x<v[i])
        {
            ok(x+1);
            x++;
        }
     //   cout<<v[i]<<" "<<a<<endl;
        ans+=a;
    }
    cout<<fixed<<setprecision(7)<<ans<<endl;
}