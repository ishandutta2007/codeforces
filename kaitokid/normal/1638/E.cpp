#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[1000009];
string s[1000009];
int x[1000009],y[1000009],z[1000009];
ll bit[1000009];
int n;
void add(int x,ll v)
{
    while(x<=n)
    {
        bit[x]+=v;
        x+=(x&(-x));
    }
}
ll cal(int x)
{
    ll res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=(x&(-x));
    }
    return res;
}
char cc[11];
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%s",cc);
        s[i]=cc;
        if(s[i]=="Color"){
                scanf("%d%d%d",&x[i],&y[i],&z[i]);continue;}
        if(s[i]=="Query"){scanf("%d",&x[i]);continue;}
        if(s[i]=="Add"){scanf("%d%d",&x[i],&y[i]);sum[x[i]]+=y[i];}
    }
    set<pair<pair<int,int> ,int > >st;
    st.insert({{1,n},1});
    add(1,sum[1]);
    for(int i=0;i<m;i++)
    {
        if(s[i]=="Query"){
                int u=x[i];
                set<pair<pair<int,int> ,int > >:: iterator  it=st.lower_bound({{u+1,0},0});
                it--;
                int v=(*it).second;
               // cout<<u<<" "<<v<<cal(u)<<" "<<sum[v]<<" ";
                printf("%lld\n",cal(u)-sum[v]);
               // cout<<cal(u)-sum[v]<<endl;
                continue;
                }

        if(s[i]=="Add")
        {
            sum[x[i]]-=y[i];
            continue;
        }
      int u=x[i],v=y[i],f=z[i];
      set<pair<pair<int,int> ,int > >:: iterator  it=st.lower_bound({{u+1,0},0}),it2=st.lower_bound({{v+1,0},0}),it3;
      it--;
      it2--;
      pair<pair<int,int> ,int > g=(*it),h=(*it2);
      it2++;
      while(it!=it2)
      {
          pair<pair<int,int> ,int > w=(*it);
          add(max(w.first.first,u),-1*sum[w.second]);
          add(min(w.first.second,v)+1,sum[w.second]);
          it3=it;
          it3++;
          st.erase(it);
          it=it3;

      }
      st.insert({{u,v},f});
      add(u,sum[f]);
      add(v+1,-1*sum[f]);
    if(g.first.first<u){g.first.second=u-1;st.insert(g);}
    if(h.first.second>v){h.first.first=v+1;st.insert(h);}
    }
    return 0;
}