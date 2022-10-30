#include <iostream>
#include<algorithm>
#include<string>

using namespace std;


string s;
long long a,b,f1[1100000],f2[1100000],p;
bool mark[1100000];

/*long long pow(long long a1,long long b1)
{
    long long c=1;
    while(b1)
    {
        if(b1%2) c=(c*a1)%a;
        b1/=2;
        a1=(a1*a1)%a;
    }
    return c;
}*/

void print(int x)
{
    cout<<"YES"<<endl;
    for(int i=s.size()-1;i>=x;i--)
        cout<<s[i];
    cout<<endl;
    for(int i=x-1;i>-1;i--)
        cout<<s[i];
    cout<<endl;
    exit(0);
}

int main()
{
    cin>>s>>a>>b;
    reverse(s.begin(),s.end());
    f1[0]=f2[0]=1;
    for(int i=1;i<=1001000;i++)
    {
        f1[i]=(f1[i-1]*10)%a;
        f2[i]=(f2[i-1]*10)%b;
    }
    p=0;
    for(int i=0;i<s.size()-1;i++)
    {
        p=(p+(int(s[i]-'0')*f2[i]))%b;
        if(p==0)
            mark[i]=true;
    }
    p=0;
    for(int i=s.size()-1;i>0;i--)
    {
        p=(p*10+(int(s[i]-'0')))%a;
       // cout<<i<<" "<<s[i]<<" "<<p<<" "<<pow(f1[i],a-2)<<endl;
        if(mark[i-1] && s[i-1]!='0' && p==0)
            print(i);
    }
    cout<<"NO"<<endl;
}