#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin>>n>>m;
    map< int, map< int, int > > mp;
    int loop=0, eq_loop=0;
    while(m--)
    {
        char op; cin>>op;
        if(op=='+')
        {
            int u, v; cin>>u>>v;
            char c; cin>>c;
            int x = c;
            mp[u][v] = x;
            int y = mp[v][u];
            if(y==0) continue;
            loop++;
            if(y==x) eq_loop++;
        }
        if(op=='-')
        {
            int u, v; cin>>u>>v;
            int x = mp[u][v];
            int y = mp[v][u];
            mp[u][v] = 0;
            if(y==0) continue;
            loop--;
            if(y==x) eq_loop--;
        }
        if(op=='?')
        {
            int k; cin>>k;
            if(k%2==1) { if(loop==0) cout<<"NO"<<endl; else cout<<"YES"<<endl; }
            else { if(eq_loop==0) cout<<"NO"<<endl; else cout<<"YES"<<endl; }
        }
    }
}

int main() { solve(); return 0; }