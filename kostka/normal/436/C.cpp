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

ST char tab[S3][11][11];
ST bool odw[S3];
ST int por[S3][S3];
ST int rep[S6], ile[S6];
ST vector <pair <int, pair <int, int> > > E;
ST vector <int> G[1007];

int n, m, k, w;

void dfs(int a)
{
    for(int i=0; i<G[a].size(); i++)
        if(odw[G[a][i]]==0)
        {
            odw[G[a][i]] = 1;
            printf("%d %d\n", G[a][i], a);
            dfs(G[a][i]);
        }
}

int find(int a)
{
  return rep[a]==a ? a : rep[a] = find(rep[a]);
}
 
bool unia(int a, int b)
{
  int fa = find(a), fb = find(b);
  if(fa==fb)
    return false;
  if(ile[fa] <= ile[fb])
  {
    ile[fb] += ile[fa];
    rep[fa] = fb;
  }
  else
  {
    ile[fa] += ile[fb];
    rep[fb] = fa;
  }
  return true;
}

int porownaj(int a, int b)
{
    int roz = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(tab[a][i][j] != tab[b][i][j])
                roz++;
    return roz;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &w);
    for(int t=0; t<k; t++)
        for(int i=0; i<n; i++)
            scanf("%s", tab[t][i]);
    for(int i=0; i<k; i++)
        for(int j=0; j<i; j++)
            por[i][j] = por[j][i] = porownaj(i,j);
    for(int i=0; i<=k; i++)
    {
        rep[i] = i;
        ile[i] = 1; 
    }
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(i!=j)
                E.push_back(make_pair(por[i][j]*w, make_pair(i+1,j+1)));
            else
                E.push_back(make_pair(m*n, make_pair(0,i+1)));
        }
    }
    long long wyn = 0;
    sort(E.begin(), E.end());
    for(int i=0; i<SZ(E); i++)
        if(unia(E[i].second.first, E[i].second.second))
        {
            G[E[i].second.first].push_back(E[i].second.second);
            G[E[i].second.second].push_back(E[i].second.first);
            wyn += E[i].first;
        }
    printf("%lld\n", wyn);
    odw[0] = 1;
    dfs(0);
    return 0;
}