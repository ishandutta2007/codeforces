#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,j,m,mi,f,x;
    multiset <long> a;
    multiset <long>  ::iterator it;
    map < long , int > p;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>x;p[x]=1;a.insert(x);}
    for(j=0;j<n*1000;++j)
    {
        it=a.end();
        f=0;
        it--;
        m=*it;
        //cout<<m;
        m/=2;
       while(m>0)
        {
            if(p[m]==0) {f=1;p[*it]=0;a.erase(it);a.insert(m);p[m]=1;break;}
            m/=2;
        }
        if(f==0) break;
    }
    for(it=a.begin();it!=a.end();++it)
        {
            cout<<*it<<" ";
        }
    return 0;
}