#include <iostream>
#include <cstring>
#define dmax 1000003
using namespace std;
char a[dmax];
int mod1, mod2, s[dmax], r1[dmax], r2[dmax], lg;

void print(int k)
{
    cout<<"YES\n";
    for(int i=0;i<k;i++)
    {
        cout<<s[i];
    }
    while(s[k]==0)
    {
        cout<<s[k];
        k++;
    }
    cout<<'\n';
    for(int i=k;i<lg;i++)
    {
        cout<<s[i];
    }
}
int p10[dmax];

bool check0(int k)
{
    for(int i=k;i<lg;i++)
        if(s[i]!=0) return true;
    return false;
}

int main()
{
cin>>a;
cin>>mod1>>mod2;
lg=strlen(a);

for(int i=0;i<lg;i++)
    s[i]=a[i]-'0';

r1[0]=0;
r2[lg-1]=0;


p10[0]=1;
for(int i=1;i<=lg;i++)
    p10[i]=(p10[i-1]*10)%mod2;

for(int i=1;i<=lg-1;++i)
{
    r1[i]=(r1[i-1]*10+s[i-1])%mod1;
    r2[lg-i-1]=(r2[lg-i]+s[lg-i]*p10[i-1])%mod2;
}

int ok=0;
for(int i=1;i<=lg-1;i++)
{
    if(r1[i]==0 && r2[i-1]==0 && check0(i))
    {
        print(i);
        ok=1;
        break;
    }
}

if(ok==0)
    cout<<"NO\n";

    return 0;
}