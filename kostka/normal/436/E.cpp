//Bartek Kostka

//Don't bother looking.
//You are not prepared. 

#include "bits/stdc++.h"

using namespace std;

#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define FT first
#define SD second
#define SZ(x) ((int)((x).size()))
#define TAKE(a) int (a); scanf("%d",&(a));
#define TAKE2(a,b) int (a),(b); scanf("%d %d",&(a),&(b));
#define TAKE3(a,b,c) int (a),(b),(c); scanf("%d %d %d",&(a),&(b),&(c));
#define DEBUG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define DEBUGV(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS TAKE(ttt)while(ttt--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define MAXI(a,b) (a)=max((a),(b));
#define MINI(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);
#define ST static
#define IN inline
#define PII pair<int,int>
#define LL long long
#define VI vector<int>
#define VII vector < PII >
#define LD long double
ST IN void WRITE(int a) { printf("%d\n",a); }
ST IN void WRITE2(int a, int b) { printf("%d %d\n", a, b); }
const int S9 = 1000000007, S6 = 1000007, S5 = 100007, S4 = 10007, S3 = 1007 , S2 = 107;
const double E2 = 0.01, E4 = 0.0001, E6 = 0.000001, E8 = 0.00000001;

int t[2000000], odp[2000000];
bool u[2000000];
int n, k;

struct cmp1
{
    bool operator() (int a, int b)
    {
    if(t[a] == t[b])
        return a < b;
    return t[a] > t[b];
    }
};

struct cmp2
{
    bool operator() (int a, int b)
    {
    if(t[a] + t[a+n] == t[b] + t[b+n])
        return a < b;
    return t[a] + t[a+n] > t[b] + t[b+n];
    }
};

void usun_stare(priority_queue<pair<int, int> > &pq)
{
    while(!pq.empty() && u[pq.top().second]) pq.pop();
}

int main()
{
    long long ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", t + i);
        scanf("%d", t + n + i);
    }
    for(int i=0; i<n; i++)
        t[n+i] -= t[i];
    for(int i=0; i<2*n; i++)
        t[i] *= -1;
    priority_queue<pair<int, int> > single, pary;
    for(int i = 0; i < n; i++)
    {
    single.push(make_pair(t[i], i));
    pary.push(make_pair(t[i] + t[i+n], i));
    }
    while(k--)
    {
    usun_stare(single);
    usun_stare(pary);
    pair<int, int> top = single.top();
    single.pop();
    usun_stare(single);
    int p;
    if(k == 0 || pary.empty() || top.first + single.top().first > pary.top().first)
        p = top.second;
    else
    {
        p = pary.top().second;
        pary.pop();
        single.push(top);
    }
    ans -= t[p];
    if(p>=n)
        odp[p-n] = 2;
    else
        odp[p] = 1;
    u[p] = true;
    if(p < n)
        single.push(make_pair(t[p+n], p + n));
    }
    printf("%lld\n", ans);
    for(int i=0; i<n; i++)
        printf("%d", odp[i]);
    return 0;
}