#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

long long n,qw,t[5000000][5],f[5];
string s;
int a[5000000];

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        t[node][a[l]]=1;
     //   cout<<node<<" "<<l<<" "<<r<<" "<<t[node][0]<<" "<<t[node][1]<<" "<<t[node][2]<<endl;
        return;
    }
    make(2*node,l,(l+r)/2);make(2*node+1,(l+r)/2,r);
    t[node][2]=t[2*node][2]+t[2*node+1][2]+min(t[2*node][0],t[2*node+1][1]);
    t[node][1]=t[2*node][1]+t[2*node+1][1]-min(t[2*node][0],t[2*node+1][1]);
    t[node][0]=t[2*node][0]+t[2*node+1][0]-min(t[2*node][0],t[2*node+1][1]);
    //cout<<node<<" "<<l<<" "<<r<<" "<<t[node][0]<<" "<<t[node][1]<<" "<<t[node][2]<<endl;
}

void dp(int node,int l,int r,int beg,int en)
{
  //  if(w<20)
 //      cout<<node<<" "<<l<<" "<<r<<" "<<beg<<" "<<en<<" "<<f[0]<<" "<<f[1]<<" "<<f[2]<<endl;
  //  w++;
    if(l>=beg && r<=en)
    {
        f[2]+=t[node][2]+min(t[node][1],f[0]);
        f[0]=f[0]-min(t[node][1],f[0])+t[node][0];
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid)
        dp(2*node,l,mid,beg,min(mid,en));
    if(en>mid)
        dp(2*node+1,mid,r,max(mid,beg),en);
}

int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]==')')
            a[i]=1;
        else
            a[i]=0;
    }
    make(1,0,n);
    cin>>qw;
    for(int i=0;i<qw;i++)
    {
        int l,r;
        f[0]=0;f[1]=0;f[2]=0;//w=0;
        cin>>l>>r;
        dp(1,0,n,l-1,r);
        cout<<2*f[2]<<endl;
    }
}