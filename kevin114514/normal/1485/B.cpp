#include<bits/stdc++.h>
using namespace std;
int n,q,k;
int x[100100];
int ans[100100];
long long psum[100100];
int main()
{
    cin>>n>>q>>k;
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=1;i<n-1;i++)
        ans[i]=x[i+1]-x[i-1]-2;
    for(int i=1;i<n-1;i++)
        psum[i]=psum[i-1]+ans[i];
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a==b)
            cout<<k-1<<endl;
        else if(a==b-1)
        {
            cout<<x[b]-2+(k-x[a]-1)<<endl;
        }
        else
        {
            cout<<x[a+1]-2+(k-x[b-1]-1)+psum[b-1]-psum[a]<<endl;
        }
    }
    return 0;
}