//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

const int INF = 1000*1000*1000;
long sszz[1000][1000];

string st,st1[1000];
long nn,lim[10000];
struct rib {
    int b, u, c, f;
    size_t back;
};

void add_rib (vector < vector<rib> > & g, int a, int b, int c, int u) {
    rib r1 = { b, u, c, 0, g[b].size() };
    rib r2 = { a, 0, -c, 0, g[a].size() };
    g[a].push_back (r1);
    g[b].push_back (r2);
}

int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>st;
cin>>nn;

for (int i=1;i<=nn;i++)
{cin>>st1[i]>>lim[i];}

int n, k;
k=1000000;

n=st.size()+nn+28;

    vector < vector<rib> > g (n);
    int s, t;
    s=0;
    t=n-1;
    
    for (int i=0;i<st.size();i++)
    add_rib(g,0,i+1,0,1);
    for (int i=0;i<st.size();i++)
    add_rib(g,i+1,st.size()+st[i]-'a'+1,0,1);
    
    
    for (int i=1;i<=26;i++)
    for (int j=1;j<=nn;j++)
    for (int q=0;q<st1[j].size();q++)
    if (st1[j][q]==i+'a'-1)
    sszz[i][j]++;
    
    for (int i=1;i<=26;i++)
    for (int j=1;j<=nn;j++)
    add_rib(g,i+st.size(),st.size()+26+j,j,sszz[i][j]);
    
    for (int i=1;i<=nn;i++)
    add_rib(g,st.size()+26+i,n-1,0,lim[i]);
    
/*  for (int i=0;i<g.size();i++)
    {
        cout<<"Q "<<i<<endl;
        for (int j=0;j<g[i].size();j++)
        {cout<<g[i][j].c<<" "<<g[i][j].u<<" "<<g[i][j].b<<endl;}
        cout<<endl<<endl;
    }
    */
    
    int flow = 0,  cost = 0;
    while (flow < k) {
        vector<int> id (n, 0);
        vector<int> d (n, INF);
        vector<int> q (n);
        vector<int> p (n);
        vector<size_t> p_rib (n);
        int qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;
            if (qh == n)  qh = 0;
            for (size_t i=0; i<g[v].size(); ++i) {
                rib & r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b]) {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0) {
                        q[qt++] = r.b;
                        if (qt == n)  qt = 0;
                    }
                    else if (id[r.b] == 2) {
                        if (--qh == -1)  qh = n-1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_rib[r.b] = i;
                }
            }
        }
        if (d[t] == INF)  break;
        int addflow = k - flow;
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v];
            addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
        }
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
            g[pv][pr].f += addflow;
            g[v][r].f -= addflow;
            cost += g[pv][pr].c * addflow;
        }
        flow += addflow;
    }
    if (flow<st.size())cout<<-1<<endl;else
    cout<<cost<<endl;//<<" "<<flow<<endl;
cin.get();cin.get();
return 0;}