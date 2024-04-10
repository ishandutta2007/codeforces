#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>

using namespace std;

long long b[1000000+100],ans;
int n,a[1000000+100];
map<int,int>m,t;
vector<int>v;

void add(int x)
{
    while(x<=1000000+100)
    {
        b[x]++;
        x+=(x&(-x));
    }
}

void f(int x)
{
    while(x>0)
    {
        ans+=b[x];
        x-=(x&(-x));
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        t[a[i]]++;
        v.push_back(t[a[i]]);
    }
    for(int i=n-1;i>0;i--)
    {
        m[a[i]]++;
        add(m[a[i]]);
        f(v[i-1]-1);
      //  cout<<m[a[i]]<<" "<<v[i-1]<<" "<<ans<<endl;
    }
    printf("%lld\n",ans);
}