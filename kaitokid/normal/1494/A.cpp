#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

    string s;
    int a[3];
    bool ch()
    {
        int d=0;
        for(int i=0;i<s.size();i++)
        {
            if(a[s[i]-'A'])d++;
            else d--;
            if(d<0)return false;
        }
        return d==0;
    }
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>s;
    bool ans=false;
    for( a[0]=0;a[0]<2;a[0]++)
    for( a[1]=0;a[1]<2;a[1]++)
    for( a[2]=0;a[2]<2;a[2]++)
    {
        if(ch()){ans=true;break;}
    }
   if(ans)cout<<"YES\n";
   else cout<<"NO\n";
}
    return 0;
}