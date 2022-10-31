#include <bits/stdc++.h> //  l   ( 2  ) ,   3

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
const int maxn = 3e5+500, base = 1e9+7,maxm=1e6+500;
int gcd(int a,int b)
{
    if (a==-1)
        return b;
    if (b==-1)
        return a;
    return b ? gcd(b,a%b) : a;
}
   int lg[maxn];
   int a[maxn];
int op(int a,int b)
{
    return gcd(a,b);
}
    int n;
    int f[30][maxn];
void build(){

  for (int i=0;i<n;i++)
            f[1][i] = a[i];
  for (int k = 0; 1 << k < n; k++)
    for (int i = 0; i + (1 << k) < n; i++){
        {
            f[k+2][i] = op(f[k+1][i],f[k+1][i+(1 <<k )]);
            //cerr<<f[k+2][i]<<endl;
        }
    }
}

int rmq(int l,int r)
{
    if ( l > r)
        swap(l , r);
    int len = r-l + 1 ;
    int k = 0;
    while (len){
        k++;
        len/=2;
    }
   // k--;

    int r1 = r-(1<<(k-1)) +1;
    //cerr<<r1<<endl;
    return op(f[k][l], f[k][r1]);
}
set<pair<int,int> > ans[maxn];

int main()
{
   // files1;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
            scanf("%d",a+i);
    }
    int _mx = -1;
  //  for ()
    build();
    for (int i=0;i<n;i++){

        int cur = a[i];
        int ansl,ansr;
        int l = 0, r = i;
        while(r - l > 1){
            int m = (l+r) / 2;
            int g = rmq(m,i);
            if (g!=cur)
                l = m;
            else
                r = m;
        }
        int g = rmq(l,i);
        if (l+1==r&&g==cur)
            r--;
        ansl = r;
            int s = clock();
        l = i, r = n-1;
        while(r - l > 1)
        {
            int m = (l+r) / 2;

             g = rmq(i,m);
            if (g!=cur)
                r = m;
            else
                l = m;
        }
          //      fprintf(stderr,"%d\n",clock()-s);
         g = rmq(i,r);
        if (l+1==r&&g==cur)
            l++;
        ansr = l;
        cur = ansr - ansl;

        if (cur >= _mx){
            ans[cur].insert(mp(ansl,ansr));
            _mx = cur;
        }

    }
    printf("%d %d\n",ans[_mx].size(),_mx);

    for (auto i:ans[_mx])
    {
        printf("%d ",i.first+1);
    }
	return 0;
}