#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
string s;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int x;
        cin>>x>>s;
        ll len=s.size(),bk=s.size();
        bool flag=false;
        for(int i=0;i<x;i++)
        {
            if(i>=s.size()) break;
            if(!flag)
            {
                if(bk>0) bk--;
                string k=s.substr(i+1,bk);
                if(s[i]-'0'==2) s+=k;
                if(s[i]-'0'==3) s+=k+k;
                len=(len+bk*(s[i]-'0'-1))%mod;
                bk=bk*(s[i]-'0')%mod;
                if(len>x) flag=true;
            }
            else
            {
                if(bk>0) bk--;
                len=(len+bk*(s[i]-'0'-1))%mod;
                bk=bk*(s[i]-'0')%mod;
            }
        }
        printf("%lld\n",len);
    }
}