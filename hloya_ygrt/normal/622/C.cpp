#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int MAXN = 2e5+500, base = 1e9+7;

    pair<int,int> t[4*MAXN], t1[4*MAXN];
void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = mp(a[tl],tl);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = min(t[v*2] , t[v*2+1]);
	}
}

pair<int,int> rmq (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return mp(inf,0);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min(rmq (v*2, tl, tm, l, min(r,tm)) , rmq (v*2+1, tm+1, tr, max(l,tm+1), r));
}


pair<int,int> rmq1 (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return mp(inf,0);
	if (l == tl && r == tr)
		return t1[v];
	int tm = (tl + tr) / 2;
	return min(rmq1 (v*2, tl, tm, l, min(r,tm)) , rmq1 (v*2+1, tm+1, tr, max(l,tm+1), r));
}
    int a[MAXN], b[MAXN];
int main()
{
    int n,m;
   // files1;
  //  fast_io;
  int asioj;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
        b[i] = a[i]*(-1);
    }
    build(a,1,0,n-1);
    for (int i=0;i<4*n;i++)
        {t1[i] = t[i];t[i] = mp(inf,inf);}

    build(b,1,0,n-1);

    for (int i=0;i<m;i++){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        pair<int,int> mn = rmq(1,0,n-1,l-1,r-1), mx = rmq1(1,0,n-1,l-1,r-1);

        if (mn.f <0 )
            mn.f*=-1;
        if (mx.f <0)
            mx.f*=-1;
       // cout<<mn.f<<' '<<mn.s<<' '<<mx.f<<' '<<mx.s<<endl;
        if (mn.first != x)
        {
            cout<<mn.second + 1<<'\n';
            continue;
        }
        if (mx.first != x)
        {
            cout<<mx.second + 1<<'\n';
            continue;
        }
        cout<<"-1\n";
    }
	return 0;
}