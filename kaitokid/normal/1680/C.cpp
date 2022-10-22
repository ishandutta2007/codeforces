#include<bits/stdc++.h>
using namespace std;
string s;
int num;
bool ch(int x)
{
    int n=s.size();
    int i=0,j=0,tmp=0,cur=0;
    while(i<n)
    {
        if(s[i]=='0')tmp++;else cur++;
        while(tmp>x){if(s[j]=='0')tmp--;else cur--; j++;}
        if(num-cur<=x)return true;
        i++;
    }
    return false;
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
        num=0;
        for(int i=0;i<s.size();i++)
        if(s[i]=='1')num++;

        int l=0,r=s.size();
        while(l<r)
        {
            int mid=(l+r)/2;
            if(ch(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;


    }

    return 0;
}