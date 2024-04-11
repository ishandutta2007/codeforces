#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007, DWA = 524288, INF = 1000*1000*1000;
vector <pair <int, int>> P;
vector <pair <int, pair <int, int>>> R;
vector <int> W;
vector <int> M;
map <int, int> N;
long long wyn[MAXN];
int NN, K;

static int ile[2*DWA], op, ok, oile;

int lsyn(int v)
{
   return 2*v;
} 

int psyn(int v)
{
   return 2*v+1;
}

//this part comes from XX POI 
//author: Michal Adamczyk

int dd[2*DWA]; // drzewa dojrzale
int nd_w[2*DWA]; // drzewa niedojrzale - wartosc w wezle
int nd_max[2*DWA];

void wstawDojrzale(int a) {
    int v = DWA + a;
    dd[v] += M[a+1]-M[a];
    while (v != 1) {
        v /= 2;
        dd[v] = dd[2*v] + dd[2*v+1];
    }
}

long long ileDojrzalych(int a, int b) {
    int va = DWA + a, vb = DWA + b;
    long long wyn = dd[va];
    if (va != vb) wyn += dd[vb];
    while(va / 2 != vb / 2) {
        if (va%2 == 0) wyn += dd[va+1];
        if (vb%2 == 1) wyn += dd[vb-1];
        va /= 2, vb /= 2;
    }
    return wyn;
}

inline void przesun_nizej(int v) {
    int ile = nd_w[v];
    nd_w[v] = 0;
    nd_w[2*v] += ile;
    nd_max[2*v] += ile;
    nd_w[2*v+1] += ile;
    nd_max[2*v+1] += ile;
}

void ustawWysokosc(int a, int x) {
    int v = DWA + a;
    nd_w[v] = x;
    nd_max[v] = x;
    while (v != 1) {
        v /= 2;
        nd_max[v] = nd_w[v] + max(nd_max[2*v], nd_max[2*v+1]);
    }
}

void zwieksz(int v, int p, int k, int p_b, int k_b) {
    // v - indeks tablicy odpowiadajcy przedzialowi bazowemu [p_b, k_b]
    if (k < p_b || k_b < p || p_b > k_b)
        return;

    if (p <= p_b && k_b <= k) {
        nd_w[v]++;
        nd_max[v]++;
        return;
    }

    if(nd_w[v] > 0)
        przesun_nizej(v);

    int m = (p_b + k_b) / 2;
    zwieksz(2*v, p, k, p_b, m);
    zwieksz(2*v+1, p, k, m+1, k_b);

    nd_max[v] = max(nd_max[2*v], nd_max[2*v+1]);
}

void znajdzDojrzale(int v, int p, int k, int p_b, int k_b) {
    if(nd_max[v] < K || k < p_b || k_b < p || p_b > k_b)
        return;

    if(p_b == k_b) {
        wstawDojrzale(p_b);
        ustawWysokosc(p_b, -INF);
        return;
    }

    if(nd_w[v] > 0)
        przesun_nizej(v);

    int m = (p_b + k_b) / 2;
    znajdzDojrzale(2*v, p, k, p_b, m);
    znajdzDojrzale(2*v+1, p, k, m+1, k_b);
}

////////////////////////////

void zmien(int gdz, int p, int k)
{
    if(op<=p && k<=ok)
    {
        ile[gdz] += oile;
        return;
    }
    //printf("%d %d\n", p, k);
    int m=(p+k)/2;
    if(op<m)
        zmien(lsyn(gdz),p,m);
    if(ok>m)
        zmien(psyn(gdz),m,k);
}

int zlicz(int x)
{
   int res = 0;
   x += DWA;
   while(x)
   {
      res += ile[x];
      x /= 2;
   }
   return res;
   cerr << res << "\n";
}

long long count(int gdz, int p, int k)
{
    long long res = 0;
    for(int i=op; i<ok; i++)
    {
       cerr << ile[i+DWA] << " ";
       if(ile[i+DWA]==0)
          res += M[i+1]-M[i];
    }
    cerr << "\n";
    return res;
}

int main()
{
  int n;
  scanf("%d", &n);
  P.resize(n);
  for(int i=0; i<n; i++)
  {
    scanf("%d%d", &P[i].first, &P[i].second);
    W.push_back(P[i].first);
    W.push_back(P[i].first+P[i].second);
  }
  sort(W.begin(), W.end());
  int nr = 0;
  for(int i=0; i<(int)W.size(); i++)
  {
    M.push_back(W[i]);
    N[W[i]] = nr++;
    while(i+1<(int)W.size() and W[i]==W[i+1])
      i++;
  }
  for(int i=0; i<n; i++)
    R.push_back({N[P[i].first], {DWA, N[P[i].first+P[i].second]}});
  int m;
  scanf("%d", &m);
  for(int i=0; i<m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    R.push_back({N[P[a-1].first], {i, N[P[b-1].first]}});
  }
  for(int i=0; i<n; i++)
  {
    op = N[P[i].first];
    ok = N[P[i].first+P[i].second];
    oile = 1;
    zmien(1,0,DWA);
  }
  NN = nr;
  K = 1000*1000;
  for(int i=0; i<nr; i++)
     ustawWysokosc(i, 1000*1000-zlicz(i));
  sort(R.begin(), R.end());
  for(int i=0; i<(int)R.size(); i++)
  {
    int f = R[i].second.first;
    if(f==DWA)
       zwieksz(1,R[i].first,R[i].second.second-1,0,DWA-1);
    else
    {
       op = R[i].first;
       ok = R[i].second.second-1;
       znajdzDojrzale(1,op,ok,0,DWA-1);
       wyn[f] = ileDojrzalych(op,ok);
    }
  } 
  for(int i=0; i<m; i++)
    printf("%I64d\n", wyn[i]);
}