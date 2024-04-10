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
#include<unordered_set>
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
#define int long long

const int MAXN=1e6;
int n,m,k;

unordered_set<int> G[MAXN];
long long deg[MAXN];
long long T[MAXN];
int H [MAXN];
long long  U[MAXN];
long long E[MAXN];
bool seen[MAXN];
bool wysycony(int a)
{
    return abs(U[a])>=E[a];
}

void wysyc(int a)
{
    //what(a+1);
    for(int b:G[a])
        if(H[a]==H[b])
        {
        if(U[a]>0)
            U[a]--,U[b]++;
        else
            U[a]++,U[b]--;
        E[a]--,E[b]--;
        G[b].erase(a);
        if(wysycony(b) && seen[b])
            wysyc(b);
        }
    G[a].clear();
}



int32_t main()
{
    _upgrade;
    int n;
    cin>>n;
    rep(i,n)cin>>T[i];
    rep(i,n) cin>>H[i];

    rep(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        --a,--b;
        G[a].insert(b);
        G[b].insert(a);
        deg[a]++;
        deg[b]++;
        if(H[a]==H[b]) E[a]++,E[b]++;
        if(H[a]>H[b]) U[a]++,U[b]--;
        if(H[a]<H[b]) U[a]--,U[b]++;
    }
    vector<int> X;
    rep(i,n) X.push_back(i);
    sort(all(X), [&](auto a, auto b){ return T[a]>T[b];});

    for(int a:X)
        {
        seen[a]=true;
        if(wysycony(a)) wysyc(a);
        }



        long long res=0;
        rep(i,n)
        {
            long long  x= wysycony(i) ? (deg[i]-abs(U[i]))/2+abs(U[i]) : ((deg[i]+1)/2);
            res+=x*T[i];

        }
    cout <<res<<endl;
}