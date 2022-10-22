#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN=200000;
const int mod=998244353;

struct mat
{
    int a[3][3];
    mat(){memset(a,0,sizeof a);}
    mat operator *(const mat &A) const
    {
        mat res;
        rep(i,0,2) rep(k,0,2) rep(j,0,2) res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*A.a[k][j])%mod;
        return res;
    }
};

ll qp(ll a,int b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int mark[MAXN+5],invp[MAXN+5],q[MAXN+5];

struct segt
{
    #define ls i*2
    #define rs i*2+1
    mat a[MAXN*4+5];
    void pu(int i) {a[i]=a[rs]*a[ls];}
    void chg(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr)
        {
            int IP=invp[l];
            int Q=q[l];
            if(mark[l]==0)
            {
                a[i].a[0][1]=(a[i].a[0][1]-1ll*IP*Q%mod+mod)%mod;
                a[i].a[1][1]=(a[i].a[1][1]-(1ll*IP*Q+1)%mod+mod)%mod;
            }
            else
            {
                a[i].a[0][1]=(a[i].a[0][1]+1ll*IP*Q)%mod;
                a[i].a[1][1]=(a[i].a[1][1]+1ll*IP*Q+1)%mod;
            }
            mark[l]^=1;
            return;
        }
        if(r<ql || qr<l) return;
        int mid=(l+r)>>1;
        chg(ls,l,mid,ql,qr);
        chg(rs,mid+1,r,ql,qr);
        pu(i);
    }
    void build(int i,int l,int r)
    {
        if(l==r)
        {
            int IP=invp[l];
            int Q=q[l];
            a[i].a[0][0]=1;
            a[i].a[0][2]=IP;
            a[i].a[1][2]=IP;
            a[i].a[2][2]=1;
            if(mark[l]==0)
            {
                a[i].a[0][1]=1ll*Q*IP%mod;
                a[i].a[1][1]=(1ll*Q*IP+1)%mod;
            }
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
}t;

int main()
{
	int n,Q; scanf("%d%d",&n,&Q);
	rep(i,1,n)
	{
        int x; scanf("%d",&x);
        int p=1ll*x*qp(100,mod-2)%mod;
        q[i]=(mod+1-p)%mod;
        invp[i]=qp(p,mod-2);
	}
    mark[1]=1;
	t.build(1,1,n);
	while(Q--)
    {
        int x; scanf("%d",&x);
        t.chg(1,1,n,x,x);
        printf("%d\n",t.a[1].a[0][2]);
    }
    return 0;
}