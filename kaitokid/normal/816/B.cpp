#include <bits/stdc++.h>

using namespace std;
int a[200002];
int b[200002];
int main()
{int n,k,q,x,y;
cin>>n>>k>>q;
for(int i=0;i<n;i++)
{
    cin>>x>>y;
    a[x]+=1;
    a[y+1]-=1;
}
for(int i=1;i<200001;i++)
{a[i]=a[i-1]+a[i];
if(a[i]>=k){b[i]+=1;}
b[i]=b[i-1]+b[i];

}
for(int i=0;i<q;i++)
{
    cin>>x>>y;
    cout<<b[y]-b[x-1]<<endl;
}
    return 0;
}