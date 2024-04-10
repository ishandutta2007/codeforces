#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[109];
int main()
{
 ios::sync_with_stdio(0);
 cin.tie(NULL);
int t,n,d;
cin>>t;
while(t--)
{
    string x,y;
    cin>>x>>y;
    int s1=x.size(),s2=y.size();
    int s=s1/(__gcd(s1,s2));
    string ans="";
    for(int i=0;i<s;i++)ans+=y;
    bool res=true;
    for(int i=0;i<ans.size();i++)
        if(ans[i]!=x[i%s1]){res=false;break;}
        if(res)cout<<ans<<endl;
        else cout<<-1<<endl;

}
    return 0;
}