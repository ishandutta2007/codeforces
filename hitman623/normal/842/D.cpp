#include <bits/stdc++.h>
#define pb push_back
#define long int
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long g=1,trie[10000005][2]={0},val[10000005]={0};
void add(long a)
{
    long i=20,node=1;
    while(i>=0)
    {
        if(trie[node][1&(a>>i)]!=0)
        node=trie[node][1&(a>>i)];
        else break;
        i--;
    }
    while(i>=0)
    {
        trie[node][1&(a>>i)]=++g;
        node=g;
        i--;
    }
}
long solve(long cur)
{
    long i=20,node=1,ans=0;
    while(i>=0)
    {
        if((cur>>i)&1)
        {
            if(val[trie[node][1]]!=(1<<(i+1))-1)
            node=trie[node][1];
            else if(trie[node][0]!=0)
            node=trie[node][0],ans+=(1<<i);
            else {ans+=(1<<i);break;}
        }
        else
        {
            if(val[trie[node][0]]!=(1<<(i+1))-1)
            node=trie[node][0];
            else if(trie[node][1]!=0)
            node=trie[node][1],ans+=(1<<i);
            else {ans+=(1<<i);break;}
        }
        i--;
    }
    return ans;
}
int main()
{
    io
    long n,m,x,cur=0,i;
    cin>>n>>m;
    for(i=0;i<n;++i)
    {
        cin>>x;
        add(x);
    }
    for(i=g;i>=1;i--)
    val[i]=1+val[trie[i][0]]+val[trie[i][1]];
    for(i=0;i<m;++i)
    {
        cin>>x;
        cur^=x;
        cout<<solve(cur)<<endl;
    }
    return 0;
}