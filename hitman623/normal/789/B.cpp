#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long long m,a[100005],i,c=0,l,b,q;
    map < long long ,long long > mp;
    cin>>b>>q>>l>>m;
    for(i=0;i<m;++i)
    {cin>>a[i];
    mp[a[i]]=1;}
    if(q==0)
    {
        if(mp[0]==0 && abs(b)<=l)
        cout<<"inf";
        else if(mp[b]==0 && abs(b)<=l)
        cout<<1;
        else cout<<0;
        exit(0);
    }
    if(b==0)
    {
        if(mp[0]==0)
        cout<<"inf";
        else cout<<0;
        exit(0);
    }
    if(abs(q)==1)
    {
        if(q==1)
        {
            if(mp[b]==0 && abs(b)<=l) cout<<"inf";
            else cout<<0;
            exit(0);
        }
        else
        {
            if((mp[b]==0 && abs(b)<=l) || (mp[-b]==0 && abs(b)<=l)) cout<<"inf";
            else cout<<0;
            exit(0);
        }
    }
    if(mp[b]==0 && abs(b)<=l) c++;
    for(i=1;i<38;++i)
    {
        b*=q;
        if(mp[b]==0 && abs(b)<=l) c++;
        if(abs(b)>l)
            break;
    }
    cout<<c;
    return 0;
}