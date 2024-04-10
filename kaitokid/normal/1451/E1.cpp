#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[2000002];
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,u,h;
cin>>n;
cout<<"AND 1 2\n";
fflush(stdout);
cin>>u;
cout<<"AND 1 3\n";
fflush(stdout);
cin>>h;
u|=h;
cout<<"OR 2 3\n";
fflush(stdout);
cin>>h;
cout<<"XOR 1 2\n";
fflush(stdout);
int d;
cin>>d;

int q=(d|h)^h;
u|=q;
a[1]=u;
a[2]=u^d;
for(int i=3;i<=n;i++)
{
    cout<<"XOR 1 "<<i<<endl;
fflush(stdout);
int x;
cin>>x;
a[i]=u^x;
}
cout<<"! ";
for(int i=1;i<=n;i++)cout<<a[i]<<" ";
fflush(stdout);

    return 0;
}