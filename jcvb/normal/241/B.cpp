#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define mo 1000000007
using namespace std;
typedef long long ll;
int n;int l=30;
ll m;
int a[50005];
struct node{
    int su[30];
    int sz,ch[2];
}t[2000000];int ndtot=1;
int head=1;
void add(int x){
    int p=head;
    for (int i=l-1;i>=0;i--){
        if(!t[p].ch[x>>i&1])t[p].ch[x>>i&1]=++ndtot;
        p=t[p].ch[x>>i&1];
        for (int j=0;j<l;j++)t[p].su[j]+=x>>j&1;
        t[p].sz++;
    }
}
int pt[50005];
int su[30]={0};
int st[30]={0};
int main()
{
    cin>>n>>m;m<<=1;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)add(a[i]);
    for (int i=1;i<=n;i++)pt[i]=head;
    for (int d=l-1;d>=0;d--){
        ll rsz=0;
        for (int i=1;i<=n;i++)rsz+=t[t[pt[i]].ch[!(a[i]>>d&1)]].sz;
        if(m>=rsz){         
            for (int i=1;i<=n;i++){
                for (int k=l-1;k>=0;k--)
                    if(a[i]>>k&1)su[k]+=t[t[pt[i]].ch[!(a[i]>>d&1)]].sz-t[t[pt[i]].ch[!(a[i]>>d&1)]].su[k];
                    else su[k]+=t[t[pt[i]].ch[!(a[i]>>d&1)]].su[k];
                pt[i]=t[pt[i]].ch[a[i]>>d&1];
            }
            m-=rsz;
        }else for (int i=1;i<=n;i++)pt[i]=t[pt[i]].ch[!(a[i]>>d&1)],st[d]=1;
    }
    for (int d=l-1;d>=0;d--)su[d]+=st[d]*m;
    ll ans=0;
    for (int i=0;i<l;i++)ans+=(1ll<<i)*su[i]/2;
    ans%=mo;
    cout<<ans<<endl;
    return 0;
}