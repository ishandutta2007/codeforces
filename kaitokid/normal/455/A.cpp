#include <iostream>

using namespace std;
unsigned long long r[1000009],ans[1000009];
int main()
{
    unsigned long long n,x,w=0,q=0;
    cin>>n;
    for (unsigned long long i=0;i<n;i++)
    {
        cin>>x;
        r[x]++;
        w=max(w,x);
    }
    
    ans[1]=r[1];
     q=max(q,ans[0]);
    for(unsigned long long i=2;i<=w;i++)
    {
        ans[i]=max(i*r[i]+ans[i-2],ans[i-1]);
    q=max(q,ans[i]);
    }
    cout<<q;
    return 0;
}