#include <bits/stdc++.h>
#define vi vector <long>
#define pb push_back
using namespace std;
long visi[200002]={0},cou,ans=0,mma=0;
long n,m,k,s[200002],i,x,y;
map < long ,vi > aa;
vector <long > cof;
void dfs(long node,long l)
{
    if(visi[node]==1) {return;}
    else if(aa[node].size()==0) return;
    else
    {   visi[node]=1;
        cou++;
        cof.pb(s[node]);
        if(aa[node].size()==1 && node!=l) {return;}
        for(long i=0;i<aa[node].size();++i)
        {
            dfs(aa[node][i],l);
        }
    }
}
int main()
{
    long t,j;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        cin>>s[i];
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        aa[x].pb(y);
        aa[y].pb(x);
    }
    if(m!=0)
    for(i=1;i<=n;++i)
    {
        if(!visi[i])
        {   mma=0;
            cou=0;
            dfs(i,i);
            t=1;
            sort(cof.begin(),cof.end());
            for(j=1;j<cof.size();++j)
            {
                if(cof[j]==cof[j-1]) t++;
                else {mma=max(mma,t);t=1;}
            }
            mma=max(mma,t);
            if(cou==0) mma=0;
            ans+=cou-mma;
            cof.clear();
        }
    }
    cout<<ans;
    return 0;
}