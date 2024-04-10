/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 3e6;
int dd[N], ss[N], digit[N], par[N];
void print(int ind)
{
    char x; string s;
    while(ind!=0) { x = '0'+digit[ind]; s += x; ind = par[ind]; }
    reverse(s.begin(), s.end()); cout<<s<<endl;
}

void solve()
{
    int d, s; cin>>d>>s;
    bool vis[d][s+1];
    memset(vis, false, sizeof(vis));
    queue<int> qu; qu.push(0);
    int cntr=0; dd[0]=0; ss[0]=0; vis[0][0]=true;
    while(!qu.empty())
    {
        int x=qu.front();qu.pop();
        int cd = dd[x], cs = ss[x];
        for(int i=0; i<=9; i++)
        {
            int nd = (cd*10+i)%d; int ns = (cs+i);
            if(ns>s || vis[nd][ns]) continue;
            cntr++; qu.push(cntr); dd[cntr]=nd; ss[cntr]=ns; digit[cntr]=i; par[cntr]=x; vis[nd][ns]=1;
            if(nd==0 && ns==s) { print(cntr); return; }
        }
    }
    cout<<-1<<endl;
}

int32_t main() { ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); solve(); return 0; }