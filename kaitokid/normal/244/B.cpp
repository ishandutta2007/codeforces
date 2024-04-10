#include <bits/stdc++.h>

using namespace std;
long long n;
set <long long> ans;

void v(long long a,long long b,long long x)
{if(x>n)return;

ans.insert(x);

v(a,b,x*10+a);
v(a,b,x*10+b);

}

int main()
{cin>>n;
    for(int i=0;i<10;i++)
{
    for(int j=i;j<10;j++)
    {
        if(i==j&&i==0){continue;}
        if(i==0){ v(i,j,j);continue;}
        if(j==0){ v(i,j,i);continue;}
        if(i!=j){v(i,j,i); v(i,j,j);continue;}
        v(i,j,i);
    }


}
cout<<ans.size();
    return 0;
}