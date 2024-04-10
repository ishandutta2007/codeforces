#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

string s;
long long n,m,a,b,c,x[200000],y[200000],z[200000],l,r;

int main()
{
    cin>>s>>m;
    if(s[0]=='x')
        x[0]++;
    else if(s[0]=='y')
        y[0]++;
    else if(s[0]=='z')
        z[0]++;
    for(int i=1;i<s.size();i++)
    {
        x[i]=x[i-1];
        y[i]=y[i-1];
        z[i]=z[i-1];
        if(s[i]=='x')
            x[i]++;
        else if(s[i]=='y')
            y[i]++;
        else if(s[i]=='z')
            z[i]++;
    }
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        r--;
        l--;
        if(r-l<2)
        {
            cout<<"YES"<<endl;
            continue;
        }
        a=x[r];b=y[r];c=z[r];
        if(l>0)
        {
            a-=x[l-1];b-=y[l-1];c-=z[l-1];
        }
        if(max(max(a,b),c)-min(min(a,b),c)>1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}