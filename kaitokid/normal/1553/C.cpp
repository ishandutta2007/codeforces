#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {

        cin>>s;
        int u=0,v=0;
        int ans=10;
        for(int i=0;i<10;i++)
        {
            if((i%2)==0 && (s[i]!='0'))u++;
            if((i%2==1) && s[i]=='1')v++;
            int r;
            if(i%2) r=(10-i-1)/2;
            else r=(10-i)/2;
            if(u>v+r){ans=i+1;break;}
        }
        u=0,v=0;
        for(int i=0;i<10;i++)
        {
            if((i%2)==1 && (s[i]!='0'))u++;
            if(((i%2)==0) && s[i]=='1')v++;
            int r;
            if(i%2==0) r=(10-i-1)/2;
            else r=(10-i)/2;
            if(u>v+r){ans=min(ans,i+1);break;}
        }
      cout<<ans<<endl;
    }
    return 0;
}