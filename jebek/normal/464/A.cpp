#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

int n,p,a[2000];
string s;

bool check(int i,int val)
{
    if(val>=p)
        return false;
    if(i>0 && val==a[i-1])
        return false;
    if(i>1 && val==a[i-2])
        return false;
    return true;
}

int main()
{
    cin>>n>>p>>s;
    for(int i=s.size()-1;i>-1;i--)
        a[i]=int(s[i]-'a');
    int x=-1;
    for(int i=s.size()-1;i>-1;i--)
    {
        if(a[i]+1<p && check(i,a[i]+1))
        {
            x=i;
            a[i]++;
            break;
        }
        if(a[i]+2<p && check(i,a[i]+2))
        {
            x=i;
            a[i]+=2;
            break;
        }
         if(a[i]+3<p && check(i,a[i]+3))
        {
            x=i;
            a[i]+=3;
            break;
        }
    }
    if(x==-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(x++;x<s.size();x++)
    {
        a[x]=0;
        while((x>0 && a[x-1]==a[x]) || (x>1 && a[x-2]==a[x]))
            a[x]++;
        if(a[x]>=p)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=0;i<s.size();i++)
        cout<<char(a[i]+'a');
    cout<<endl;
}