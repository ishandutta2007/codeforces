#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,A[N],C[N];
multiset<int>s;
multiset<int>::iterator it;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        int t=n-A[i],a,b,c;
        it=s.begin();
        a=b=c=*it;
        it=s.lower_bound(t);
        if(it!=s.end())
            b=*it;
        it=s.upper_bound(t);
        if(it!=s.end())
            c=*it;
        if((A[i]+a)%n<=(A[i]+b)%n&&(A[i]+a)%n<=(A[i]+c)%n)
            C[i]=(A[i]+a)%n,s.erase(s.find(a));
        else if((A[i]+b)%n<=(A[i]+a)%n&&(A[i]+b)%n<=(A[i]+c)%n)
            C[i]=(A[i]+b)%n,s.erase(s.find(b));
        else C[i]=(A[i]+c)%n,s.erase(s.find(c));
    }
    for(int i=1;i<=n;i++)
        printf(i==n?"%d\n":"%d ",C[i]);
}