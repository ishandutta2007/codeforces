#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long cal(string s)
{
    if(s=="S") return 1;
    if(s=="M") return 2;
    if(s=="L") return 3;
    if(s=="XL") return 4;
    if(s=="XXL") return 5;
    if(s=="XXXL") return 6;
    return 0;
}
int main()
{
    long n,a[7]={0},i,x,d[100005][2]={0},ans[100005],j,m,l;
    for(i=1;i<7;++i)
    cin>>a[i];
    cin>>n;
    char str[7][20]={"","S","M","L","XL","XXL","XXXL"};
    string s,st[2];
    for(i=0;i<n;++i)
    {
        cin>>s;
        st[0].clear();
        st[1].clear();
        m=s.length();
        l=0;
        for(j=0;j<m;++j)
        if(s[j]==',') l++;
        else st[l].pb(s[j]);
        d[i][0]=cal(st[0]);
        d[i][1]=cal(st[1]);
        if(d[i][1]==0)
        {
        ans[i]=d[i][0];
        a[d[i][0]]--;
        if(a[d[i][0]]<0) {cout<<"NO";exit(0);}
        }
    }
    for(j=1;j<=6;++j)
    {
        for(i=0;i<n;++i)
        if(!ans[i] && d[i][0]==j-1 && a[j]>0)
        {
            ans[i]=j;
            a[j]--;
        }
        for(i=0;i<n;++i)
        if( !ans[i] && d[i][0]==j && a[j]>0)
        {
            ans[i]=j;
            a[j]--;
        }
    }
    for(i=0;i<n;++i)
    if(!ans[i]) {cout<<"NO";exit(0);}
    cout<<"YES\n";
    for(i=0;i<n;++i)
    cout<<str[ans[i]]<<endl;
    return 0;
}