#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[505],b[505];
bool bl[2];
int main()
{
ios::sync_with_stdio(0);
int n,m,t;
cin>>t;
while(t--)
{
    bool d=true;
cin>>n;
cin>>a[0];
bl[0]=bl[1]=false;
for(int i=1;i<n;i++){cin>>a[i];if(a[i]<a[i-1])d=false;}
for(int i=0;i<n;i++){cin>>b[i];bl[b[i]]=true;}
if(bl[0]&&bl[1]){cout<<"Yes\n";continue;}
if(d){cout<<"Yes\n";continue;}
cout<<"No\n";
}
    return 0;
}