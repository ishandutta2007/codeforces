#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

#define f first
#define s second
#define pb push_back

vector < int > g[100007];

int sc[100007],c[100007],m,num=0;

void DFS ( int v, int p ){

    int msize = g[v].size();
    if ( sc[v] == 1 ) c[v] = c[p]+1;
    if (c[v]>m||c[p]==2e9) c[v] = 2e9;


    if ( msize == 1 && v != 1) {
        if (c[v]<2e9) num++;
        return;
    }
    for (int i =0; i<msize;i++)
        if (g[v][i]!=p) DFS(g[v][i],v);
}

int main()
{
    int n,i,ms,mf;
    cin>>n>> m;
    c[0] = 0;

    for (i=1;i<=n;i++){
        cin >> sc[i];
        c[i] = 0;
    }

    for (i=1;i<n;i++){
        cin>>ms>>mf;
        g[ms].pb(mf);
        g[mf].pb(ms);
    }
    
    DFS(1,0);
    
    
    cout<<num;
    return 0;
}