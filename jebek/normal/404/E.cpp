#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int f,MAX,l,r,x,MIN;
string s;
vector<int>v;

bool check(int k)
{
    MAX=0;
    f=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]<v[i-1])
        {
            if(v[i]+f<=k)
                f=k-v[i]+1;
        }
        else
        {
            MAX=max(MAX,v[i]+f);
        }
    }
    if(MAX>=v[v.size()-1]+f)
        return false;
    //cout<<k<<endl;
    return true;
}

int main()
{
    cin>>s;
    if(s[s.size()-1]=='L')
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L')
                s[i]='R';
            else
                s[i]='L';
        }
    }
    if(s[0]=='L')
        x=-1;
    else
        x=1;
    v.push_back(0);
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            v.push_back(x);
            MAX=max(MAX,x);
            MIN=min(MIN,x);
        }
        if(s[i]=='L')
            x--;
        else
            x++;
    }
    v.push_back(x);
    if(x>MAX)
    {
        cout<<1<<endl;
        return 0;
    }
    r=-MIN;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(-mid))
            l=mid;
        else
            r=mid-1;
    }
    cout<<l<<endl;
}