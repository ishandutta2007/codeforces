#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
#define PII pair<int, int>

const int MAXN=1e6;
const int MAXK=10;
int n,m,k;

vector<pii> G[MAXN];
vector<pii> Gp [MAXN];
bool M [MAXK][MAXK][MAXK][MAXK];


void insert(pii A, pii B)
{
    M[A.st][A.nd][B.st][B.nd]=true;
}
bool get(pii A, pii B)
{
    return M[A.st][A.nd][B.st][B.nd];
}
int32_t main()
{
    cin>>n>>m>>k;
    rep(i,m)
    {
        int u,v,w;
        cin>>u>>v>>w;

        G[--u].emplace_back(w,--v);
    }

    rep(i,n)
    {
        sort(all(G[i]));
        rep(j,sz(G[i]))
            Gp[G[i][j].nd].emplace_back(make_pair(j,sz(G[i])-1));
    }

    rep(i,n)
    {
        set<pii> tmp;
        for(auto p:Gp[i])
            {
                if(tmp.find(p)!=tmp.end())
                    insert(p,p);
                tmp.insert(p);
            }
        for(auto p:tmp)
            for(auto q:tmp)
                if(p!=q)
                    insert(p,q);
    }

    vector<int> perm;
    rep(i,k) perm.push_back(i);

    int licznik=0;
    do
    {
        vector<int> tmp=perm;
        vector<pii> S;
        for(int i=k-1;i>=0;i--)
            rep(j,sz(tmp)) if(tmp[j]==i)
                {
                   S.emplace_back(j,i);
                   tmp.erase(tmp.begin()+j);
                   break;
                   }
        for(auto s1:S) for(auto s2:S) if(get(s1,s2)) goto endloop;
        licznik++;
        endloop:
        int a=11;
       // cerr<<"ok\n";
    }
    while (next_permutation(all(perm)));
    cout<<licznik<<endl;


};