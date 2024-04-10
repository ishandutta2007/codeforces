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
const int maxn = 1e5+500, base = 1e9+7, C = (1 << 30) - 1;

struct triple
{
    int l,r,q;
    triple(){}
    triple(int l,int r,int q):l(l),r(r),q(q){}
};
void bad()
{
    cout<<"NO";
    exit(0);
}

vector<triple> events;
int t[31][maxn];
int f[25][maxn];
int a[maxn]={0};
vector<int> get_b(int q)
{
    vector<int> ans;
    for (int i=1;i<=30;i++){
        if (((1<<(i-1))&q) != 0)
            ans.pb(i);
    }
    return ans;
}

int op(int a,int b){
    return a&b;
}

    int n , m;
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
int main()
{
    //files1;
    fast_io;
    scanf("%d %d",&n,&m);

    for (int i=0;i<m;i++){
        int l, r , q;
        scanf("%d %d %d",&l,&r,&q);
        l--;
        r--;
        events.pb(triple(l,r,q));
        vector<int> s = get_b(q);
        for (int i=0;i<s.size();i++){
            t[s[i]][l] +=1;
            t[s[i]][r+1] -=1;
        }
    }

    for(int j=1;j<=30;j++){
         int balance = 0;
        for (int i=0;i<n;i++){
            balance+=t[j][i];
            t[j][i] = min(1,balance);
    }
    }
    for (int i=0;i<n;i++){

        int s=1;
        for (int j=1;j<=30;j++){
            a[i] += s*t[j][i];
            s*=2;
        }
    }

    build();
    for (int i=0;i<m;i++){
        int l=events[i].l,r=events[i].r,q=events[i].q;
        if (rmq(l,r)!=q)
            bad();
    }
    cout<<"YES\n";
    for (int i=0;i<n;i++)
        cout<<a[i]<<' ';
	return 0;
}