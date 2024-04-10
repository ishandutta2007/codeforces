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
const int maxn = 1e5+500, base = 1e9+7;
    int sx = 1;
    int f1[maxn],f2[maxn];
    int a[maxn];
    map<int,int> sot;
    vector<int> compression;
    int n ;
    ll k;

void add(int *t,int i,int x)
{
    while (i<=sx)
    {
        t[i]+=x;
        i+=i&(-i);
    }
}

int sum(int *t ,int r)
{
    int res = 0;
    while (r>0)
    {
            res+=t[r];
            r-=r&(-r);
    }
    return res;
}
int main()
{
    //files1;
    scanf("%d %I64d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
        compression.push_back(a[i]);
    }
    sort(compression.begin(),compression.end());
    for (int i=0;i<n;i++){
        if (sot.find(compression[i])!=sot.end())
            continue;
        sot[compression[i]] = sx;
        sx ++;
    }
    for (int i=0;i<n;i++)
        {
            a[i] = sot[a[i]];
      //      cerr<<a[i]<<' ';
        }
    //cerr<<endl;
    int l = 0, r = 1;
    add(f1,a[0],1);
    ll ans = 0;

    for (int i=n-1;i>=1;i--){
     //   cerr<<a[i]<<endl;
        ans += sum(f2,a[i]-1);
        add(f2,a[i],1);
        if (a[0] > a[i])
            ans++;
    }
    ll res = 0;
    while (r<n)
    {
       // cerr<<l<<' '<<r<<endl;
        while (r<n&&ans>k){
            ans-=(sum(f1,sx)-sum(f1,a[r]));
            ans-=sum(f2,a[r]-1);
            add(f2,a[r],-1);
            r++;
        }
        //cerr<<"I MOVED R TO "<<r<<endl;
        res+=n-r;
        if (l==n-2)
            break;
        if (l+1==r){
            ans-=(sum(f1,sx)-sum(f1,a[r]));
            ans-=sum(f2,a[r]-1);
            add(f2,a[r],-1);
            r++;
        }
        //a[l]
        l++;
        ans+=(sum(f1,sx)-sum(f1,a[l]));
        ans+=sum(f2,a[l]-1);
        add(f1,a[l],1);


    }
    cout<<res;
	return 0;
}