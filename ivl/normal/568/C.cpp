#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <cstring>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double
#define prr pair < real, real >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void imp(){printf("-1\n"); exit(0);}

int f(int a){if (a < 200) return a+200; return a-200;}
int f(int a, bool b){if (b) return f(a); return a;}
int Read(){
    int x;
    string s;
    cin >> x >> s;
    --x;
    if (s[0] == 'C') x = f(x);
    //TRACE(x);
    return x;
}

int gr[405];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
void join(int a, int b, int *d){
    a = un(a), b = un(b);
    if (d[a] < d[b]) gr[b] = a;
    else gr[a] = b;
}

string v;
int l;
int n, m;
vector < int > E[405];
string s;

int bio[405];
int dep[405];
void SCC(int id){
    if (bio[id]) return;
    bio[id] = 1;
    for (auto x : E[id]){
        if (bio[un(x)] == 2) continue;
        if (bio[un(x)] == 1) join(id, x, dep);
        if (bio[x] == 0){
            dep[x] = dep[id] + 1;
            SCC(x);
            if (dep[un(x)] <= dep[id]) join(id, x, dep);
        }
    } bio[id] = 2;
}

vector < int > E2[405];

int clr[405];
bool Bad;

void Reset(){
    memset(clr, 0, sizeof clr);
    Bad = false;
}

void Set(int id){
    id = un(id);
    if (clr[id] || clr[un(f(id))]){
        if (clr[id] == 1) Bad = true;
        if (clr[un(f(id))] == 2) Bad = true;
        return;
    } clr[id] = 2;
    clr[un(f(id))] = 1;
    for (auto x : E2[id]) Set(x);
}

bool bio2[405];
bool Attempt(int id){
    if (bio2[id]++) return true;
    id = un(id);
    if (clr[id]) return clr[id] == 2;
    for (auto x : E2[id]) if (!Attempt(x)) return false;
    return true;
}

void Build(int lo, int hi, string &S){
    int ID = 0;
    REP(l,i) if (v[i] != v[0]){ID = i; break;}
    FOR(lo,hi,i){
        memset(bio2, 0, sizeof bio2);
        if (Attempt(f(i, v[0]))){
            Set(f(i, v[0]));
            S[i] = 0;
        } else {
            if (ID == 0) Bad = true;
            Set(f(i, v[ID]));
            S[i] = ID;
        }
    }
}

int main(){
    REP(400,i) gr[i] = i;

    cin >> v >> n >> m;
    l = (int)v.size();
    REP(l,i) if (v[i] == 'V') v[i] = 0; else v[i] = 1;
    REP(m,i){
        int a = Read(), b = Read();
        E[a].pb(b);
        E[f(b)].pb(f(a));
    } cin >> s;
    REP(n,i) s[i] -= 'a';

    REP(400,i) SCC(i);
    REP(200,i) if (un(i) == un(f(i))) imp();
    REP(400,i) for (auto x : E[i]) if (un(i) != un(x)) E2[un(i)].pb(un(x));

    REP(n,i) Set(f(i, v[s[i]]));
    if (!Bad){REP(n,i) s[i] += 'a'; cout << s << endl; return 0;}

    string out = s;

    for (int i = n-1; i >= 0; --i){
        bool Tried[2] = {false, false};
        FOR(s[i]+1,l,x){
            if (Tried[v[x]]++) continue;
            Reset();
            REP(i,j) Set(f(j, v[s[j]])), out[j] = s[j];
            Set(f(i, v[x])), out[i] = x;
            if (Bad) continue;
            Build(i+1, n, out);
            if (Bad) continue;
            REP(n,i) out[i] += 'a';
            cout << out << endl;
            return 0;
        }
    } imp();

    return 0;
}