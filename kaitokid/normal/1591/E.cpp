#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ch[1000009];
int n,ans[1000009],st[1000009],en[1000009],fr[1000009],a[1000009],ord[1000009],pos[1000009];
vector<int>qr[1000009];
int s[1000009],k[1000009];
void add(int x)
{
    int z=en[fr[x]];
    int u=ord[z];
    swap(ord[pos[x]],ord[z]);
    swap(pos[x],pos[u]);
    st[fr[x]+1]=en[fr[x]];
    en[fr[x]]--;
    if(en[fr[x]]<st[fr[x]])st[fr[x]]=en[fr[x]]=-1;
    fr[x]++;
    if(en[fr[x]]==-1)en[fr[x]]=st[fr[x]];

}
void rem(int x)
{
    int z=st[fr[x]];
    int u=ord[z];
    swap(ord[pos[x]],ord[z]);
    swap(pos[x],pos[u]);
    en[fr[x]-1]=st[fr[x]];
    st[fr[x]]++;
    if(en[fr[x]]<st[fr[x]])st[fr[x]]=en[fr[x]]=-1;
    fr[x]--;
    if(st[fr[x]]==-1)st[fr[x]]=en[fr[x]];

}
void sol(int x)
{
    if(fr[ord[n-1]]<s[x]){
          //  cout<<x<<" "<<ord[n-1]<<" "<<fr[ord[n-1]]<<endl;
            ans[x]=-1;return;}
    int l=0,r=n-1;
    while(r>l)
    {
        int mid=(l+r)/2;
        if(fr[ord[mid]]>=s[x])
           r=mid;
        else l=mid+1;
    }
  l+=k[x]-1;
  if(l>n-1)ans[x]=-1;
  else
  ans[x]=ord[l];
}
void go(int x)
{
    add(a[x]);
    for(int i=0;i<qr[x].size();i++)sol(qr[x][i]);
    for(int i=0;i<ch[x].size();i++)go(ch[x][i]);
    rem(a[x]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>n>>q;
        for(int i=0;i<=n;i++)
        {
            ch[i].clear();
            qr[i].clear();
            st[i]=en[i]=-1;
            ord[i]=i+1;
            pos[i+1]=i;
            fr[i]=0;
        }
      st[0]=0;
      en[0]=n-1;
      for(int i=1;i<=n;i++)cin>>a[i];
      for(int i=2;i<=n;i++){int x;cin>>x;ch[x].push_back(i);}
      for(int i=0;i<q;i++)
      {
        int x;
        cin>>x>>s[i]>>k[i];
        qr[x].push_back(i);
      }
      go(1);
      for(int i=0;i<q;i++)cout<<ans[i]<<" ";
      cout<<endl;
    }
    return 0;
}