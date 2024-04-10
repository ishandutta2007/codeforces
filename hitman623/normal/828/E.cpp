#include <bits/stdc++.h>
#define pb push_back
#define long int
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string s,ss;
long n;
map < char , long > vv;
const long N = 1e5;
long t[2 * N][4][10][10]={0};

void build(long v ,long s , long j)
{ for (long i = n - 1; i > 0; --i) t[i][v][s][j-1] = t[i<<1][v][s][j-1] + t[i<<1|1][v][s][j-1]; }

void update(long v ,long s , long j , long p, long value)
{ for (t[p += n][v][s][j-1]+=value; p > 1; p >>= 1) t[p>>1][v][s][j-1] = t[p][v][s][j-1] + t[p^1][v][s][j-1]; }

long query(long v ,long s , long j,long l, long r)
{
    long res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res += t[l++][v][s][j-1];
        if (r&1) res += t[--r][v][s][j-1];
    }
    return res;
}

long main()
{
    io
    long q,x,i,j,k,l,r,cnt;
    long tt;
    char ch;
    vv['A']=0;
    vv['T']=1;
    vv['G']=2;
    vv['C']=3;
    cin>>s;
    n=s.length();
    cin>>q;
    for(i=0;i<n;++i)
    for(j=0;j<10;++j)
    for(k=1;k<=10;++k)
    if((i-j)%k==0 && i>=j)
    t[i+n][vv[s[i]]][j][k-1]=1;
    for(i=0;i<10;++i)
    for(j=1;j<=10;++j)
    for(k=0;k<4;++k)
    build(k,i,j);
    while(q--)
    {
        cin>>tt;
        if(tt==1)
        {
            cin>>x>>ch;
            x--;
            for(i=0;i<10;++i)
            for(j=1;j<=10;++j)
            if((x-i)%j==0 && x>=i)
            {
                update(vv[s[x]],i,j,x,-1);
                update(vv[ch],i,j,x,1);
            }
            s[x]=ch;
        }
        else
        {
            cin>>l>>r;
            l--;
            cin>>ss;
            cnt=0;
            for(i=0;i<ss.length();++i)
            cnt+=query(vv[ss[i]],(l+i)%ss.length(),ss.length(),l,r);
            cout<<cnt<<endl;
        }
    }
    return 0;
}