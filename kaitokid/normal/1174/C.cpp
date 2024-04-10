#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int p[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
int d=1;
for(int i=2;i<sqrt(n)+2;i++)
{
    if(p[i]>0)continue;
    p[i]=d;
    for(int j=i*i;j<=n;j+=i)p[j]=d;
    d++;
}
for(int i=2;i<=n;i++)
{
    if(p[i]==0){p[i]=d;d++;}
    cout<<p[i]<<" ";
}
    return 0;
}