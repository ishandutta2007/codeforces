#include<bits/stdc++.h>


using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long
#define _ld long double
#define mp make_pair

const int maxn = 1e5+300,inf = 2e9,eps = 1e-8;

pair <int,int> a[maxn];
int good[maxn], len[maxn];

int n,p;



_ld _try2(int j) {
    return (_ld)((_ld)good[j]/len[j])*(_ld)((_ld)good[j-1]/len[j-1])*(_ld)2000;
}

_ld last()
{
    return (_ld)((_ld)good[n-1]/len[n-1])*(_ld)((_ld)good[0]/len[0])*(_ld)2000;
}

void _try(int j) {
    good[j]=a[j].s/p-(a[j].f-1)/p;
    len[j]=a[j].s-a[j].f+1;
}

_ld form(int j)
{
   return (_ld)(4000.00*(good[j]/(1.0 * len[j] )));
}
int main()
{
    scanf ("%d%d",&n,&p);
    for (int j=0;j<n;j++){
        int x1,y1;
        scanf ("%d%d",&x1,&y1);
        a[j].f = x1;
        a[j].s = y1;
        _try(j);
    }
    _ld ans = 0;

    for (int j=0;j<n;j++)
        ans += form(j);

    for (int j=1;j<n; j++ )
        ans -= _try2(j);

    ans -=last();
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}