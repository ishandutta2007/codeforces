#include <iostream>
#include <cstdio>
using namespace std;

long long c0[100];
long long c1[100];


void solve()
{

long long s, x;
long long c=0;
cin>>s>>x;
if(s==x)
    c=-2;
long long i=0;
if(x%2==1 && s%2==0)
{
    cout<<0<<'\n';
    return;
}

if(x%2==0 && s%2==1)
{
    cout<<0<<'\n';
    return;
}
if(s%2==0)
{
c0[1]=1;
c1[1]=1;
}
else{
    c0[1]=2;
    c1[1]=0;
}
i++;
x/=2;
s/=2;
long long r=s%2;
while(s!=0 || x!=0)
{
    if(x%2==0)// biti egali
    {
        if(s%2==0)
        {
            c0[i+1]=c0[i];
            c1[i+1]=c0[i];
        }
        else{
            c0[i+1] = c1[i];
            c1[i+1] = c1[i];
        }
    }
    else{// biti diferiti

        if(s%2==0)
        {
            c0[i+1]=0;
            c1[i+1]=2*c1[i];
        }
        else{
            c0[i+1] = 2*c0[i];
            c1[i+1] = 0;
        }
    }
    i++;
    r=s%2;
    s/=2;
    x/=2;
}




    if(x%2==0)// biti egali
    {
        if(s%2==0)
        {
            c0[i+1]=c0[i];
            c1[i+1]=c0[i];
        }
        else{
            c0[i+1] = c1[i];
            c1[i+1] = c1[i];
        }
    }
    else{// biti diferiti

        if(s%2==0)
        {
            c0[i+1]=0;
            c1[i+1]=2*c1[i];
        }
        else{
            c0[i+1] = 2*c0[i];
            c1[i+1] = 0;
        }
    }
    i++;
    r=s%2;
    s/=2;
    x/=2;


cout<<c0[i]+c<<'\n';
}

int main()
{
    /*
    freopen("in.txt", "r", stdin);
    freopen("o1.txt", "w", stdout);
long long n;
cin>>n;
*/
//for(long long i=1;i<=n;i++)
solve();

/*
if(r%2==0)
cout<<c0[i]+c+c1[i-1]<<'\n';
else cout<<c1[i]+c0[i+1]+c<<'\n';
  */  return 0;
}