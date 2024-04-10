/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 3e5 + 100;
int a[N];
int b[N];

int n;
int bst=0;
int pa=0;
int pb=0;

int get_taste(int cnta, int cntb)
{
    if(cnta>n) return -1;
    if(cntb>n) return -1;
    if(cnta+cntb!=n) return -1;

    int ans = bst;

    if(cnta>pa)
    {
        int l = cnta-pa;
        ans += b[l];
    }
    else
    {
        int l = cntb-pb;
        ans += a[l];
    }

    return ans;
}

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

int H = 450;

void solve(int x, int y)
{
    int g = GCD(x, y);
    if(n%g!=0) { cout<<-1<<endl; return; }

    int c = n/H;

    if(x>c)
    {
        int ans = -1;

        for(int i=0; 1; i++)
        {
            int ca = (i*x);
            int cb = (n-ca);

            if(ca>n) break;
            if(cb%y!=0) continue;

            int cur = get_taste(ca, cb);
            ans = max(cur, ans);
        }

        cout<<ans<<endl;
        return;
    }

    if(y>c)
    {
        int ans = -1;

        for(int i=0; 1; i++)
        {
            int cb = (i*y);
            int ca = (n-cb);

            if(cb>n) break;
            if(ca%x!=0) continue;

            int cur = get_taste(ca, cb);
            ans = max(cur, ans);
        }

        cout<<ans<<endl;
        return;
    }

    int minx = -1;

    for(int i=0; 1; i++)
    {
        int ca = (i*x);
        int cb = (n-ca);

        if(ca>n) break;
        if(cb%y!=0) continue;

        minx = ca;
        break;
    }

    if(minx==-1) { cout<<-1<<endl; return; }

    if(minx>=pa)
    {
        int ans = get_taste(minx, n-minx);
        cout<<ans<<endl; return;
    }

    //cout<<minx<<" "<<x<<" "<<y<<" "<<g<<endl;
    //cout<<pa<<" "<<pb<<endl;

    int xyg = (x*y)/g;

    int dif = pa-minx;
    int d1 = dif%xyg;
    int d2 = xyg-d1;

    int ans1 = get_taste(pa-d1, pb+d1);
    int ans2 = get_taste(pa+d2, pb-d2);
    int ans = max(ans1, ans2);

    cout<<ans<<endl;
    return;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        int va, vb;
        cin>>va>>vb;
        bst+=max(va, vb);
        if(va>vb) a[++pa]=vb-va;
        else b[++pb]=va-vb;
    }

    sort(a+1, a+pa+1);  reverse(a+1, a+pa+1);
    sort(b+1, b+pb+1);  reverse(b+1, b+pb+1);

    //cout<<"Best = "<<bst<<endl;

    //cout<<"a[] - ";
    //for(int i=1; i<=pa; i++) cout<<a[i]<<" ";
    //cout<<endl;

    //cout<<"b[] - ";
    //for(int i=1; i<=pb; i++) cout<<b[i]<<" ";
    //cout<<endl;

    a[0]=0; b[0]=0;
    for(int i=1; i<=pa; i++) a[i]+=a[i-1];
    for(int i=1; i<=pb; i++) b[i]+=b[i-1];

    int q; cin>>q;
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        solve(x, y);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}