#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main()
{
    long long n,i,mn=0,mx=0,f,j;
    char a[1003],b[1003];
    map < long , long > m,s;
    cin>>n;
    cin>>a>>b;
    for(i=0;i<n;++i)
        {s[a[i]-'0']++;
        m[b[i]-'0']++;}
    for(i=0;i<n;++i)
    {
        f=0;
        for(j=a[i]-'0';j<=9;++j)
        if(m[j]>0) {f=1;m[j]--;break;}
        if(f==0)
        {for(j=0;j<=9;++j) if(m[j]>0) {m[j]--;break;}
        mn++;}
    }
    m.clear();s.clear();
    for(i=0;i<n;++i)
        {s[a[i]-'0']++;
        m[b[i]-'0']++;}
    for(i=0;i<n;++i)
    {
        f=0;
        for(j=a[i]-'0'+1;j<=9;++j)
        if(m[j]>0) {mx++;f=1;m[j]--;break;}
        if(f==0) for(j=0;j<=9;++j) if(m[j]>0) {m[j]--;break;}
    }
    cout<<mn<<endl<<mx;
    return 0;
}