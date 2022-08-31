#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

void gett()
{
    cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
ll inv(ll a, ll mod)
{
    return powr(a,mod-2,mod);
}

const int maxn = 1e6+10;
const ll mod = 1e6+3;
int N = 110;
const int M = 1e6+3;
const int MAXN = 201;
struct matrix{
    int m[MAXN][MAXN];//increase it if bigger matrices are required
    matrix(){memset(m,0,sizeof m);}
    matrix(vvi& vec)
    {
        rep(i,0,sz(vec))
        rep(j,0,sz(vec[0]))
        m[i][j] = vec[i][j];
    }
    void operator = (matrix mat)
    {
        rep(i,0,N)
        rep(j,0,N)
        m[i][j] = mat.m[i][j];
    }
    void takemod()
    {
        rep(i,0,N)
        rep(j,0,N)
        m[i][j]%=M;
    }
    void operator += (matrix& mat)
    {
        rep(i,0,N)
        rep(j,0,N)
        m[i][j]+=mat.m[i][j];
    }
    void operator -= (matrix& mat)
    {
        rep(i,0,N)
        rep(j,0,N)
        m[i][j]-=mat.m[i][j];
    }
    matrix operator + (matrix& mat)
    {
        matrix ret = (*this);
        ret += mat;
        return ret;
    }
    matrix operator - (matrix& mat)
    {
        matrix ret = (*this);
        ret -= mat;
        return ret;
    }
    matrix operator * (matrix& b)
    {
    matrix c = matrix();
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j) 
                c.m[i][j] = (c.m[i][j] + 1LL * m[i][k] * b.m[k][j]) % M;
        return c;
    }
    void operator *= (matrix& b)
    {
        *this = ((*this)*b);
    }
    matrix modpow(ll n)
    {
        matrix I = matrix(),A = (*this);
        rep(i,0,N)
        I.m[i][i] = 1;
        while(n)
        {
            if(n&1)
                I *= A;
            A *= A;
            n>>=1;
        }
        return I;
    }
    void matprint()
    {
        rep(i,0,N)
        {
            rep(j,0,N)
            printf("%d ",m[i][j]);
            printf("\n");
        }
        printf("\n");
    }
};

// F(N) = F(N-1) + H*F(N-2)+.....H^W * F(N-W -1)
// precompute for N<=W

ll F[MAXN];
int main()
{
	int c,w,h;
	sd(c),sd(w),sd(h);
	int C=c,W=w,H=h;
	F[0] = 1;
	matrix A = matrix();
	for(int i = 1;i<=W;i++){
		ll mul = 1;
		ll ret = 0;
		for(int j = 0;j<=w && j<=i ; j++)
		{
			if(j == i)
				ret = (ret+mul)%mod;
			else
			{
				ret = (ret+mul*F[i-j-1])%mod;
			}
			mul = (mul*h)%mod;
		}
		F[i] = ret;
	}
	if(C<=w){
		cout<<F[C]<<endl;
		return 0;
	}
	ll mul = 1;
	for(int i = 0;i<=w;i++)
	{
		A.m[0][i] = mul;
		mul = (mul*h)%mod;
	}
	for(int i = 1;i<=w;i++)
		A.m[i][i-1] = 1;
	A = A.modpow(C-W);
	ll ans = 0;
	for(int i = 0;i<=w;i++)
	{
		ans = (ans+F[w-i]*A.m[0][i])%mod;
	}
	cout<<ans;
}