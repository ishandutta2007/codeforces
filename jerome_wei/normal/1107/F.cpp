#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 510;
const ll INF = 10000000000000000LL;
const ll inf = 5000000000000LL;

int n;

int nx, ny;
int times;
ll v[MAXN][MAXN];
ll ex[MAXN], ey[MAXN];
ll slack[MAXN];
int ux[MAXN], uy[MAXN], mx[MAXN], my[MAXN], pre[MAXN];
template<class T>
inline void freshmin(T &a, const T &b)
{
    if (a > b) a = b;
}

void match(int y)
{
    while (y)
    {
        my[y] = pre[y];
        swap(y, mx[pre[y]]);
    }
}

void bfs(int sx)
{
    for (int y = 1; y <= ny; ++ y)
        slack[y] = INF;
    queue<int> Q;
    Q.push(sx);
    ++ times;
    while (1)
    {
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            ux[x] = times;
            ll gap;
            for (int y = 1; y <= ny; ++ y)
                if (uy[y] != times && (gap = ex[x]+ey[y]-v[x][y]) <= slack[y])
                {
                    pre[y] = x;
                    if (!gap)
                    {
                        uy[y] = times;
                        if (!my[y])
                            return match(y);
                        else
                            Q.push(my[y]);
                    }
                    else
                        slack[y] = gap;
                }
        }
        ll d = INF;
        for (int y = 1; y <= ny; ++ y)
            if (uy[y] != times) freshmin(d, slack[y]);
        for (int x = 1; x <= nx; ++ x)
            if (ux[x] == times) ex[x] -= d;
        for (int y = 1; y <= ny; ++ y)
            if (uy[y] == times) ey[y] += d; else slack[y] -= d;
        for (int y = 1; y <= ny; ++ y)
            if (uy[y] != times && !slack[y])
            {
                uy[y] = times;
                if (!my[y])
                    return match(y);
                else
                    Q.push(my[y]);
            }
    }
}

void KM()
{
    for (int y = 1; y <= ny; ++ y)
    {
        my[y] = 0;
        ey[y] = 0;
        uy[y] = 0;
    }
    for (int x = 1; x <= nx; ++ x)
    {
        mx[x] = 0;
        ex[x] = *max_element(v[x]+1, v[x]+ny+1);
        ux[x] = 0;
    }
    for (int x = 1; x <= nx; ++ x)
        bfs(x);
    ll ans = 0;
    for (int y = 1; y <= ny; ++ y)
        ans += v[my[y]][y];
    cout << ans << endl;
}

int main()
{
	scanf("%d",&n);
//	S=n*2+1,T=n*2+2;
//	for(ll i=1;i<=n;i++)adde(S,i,1,0),adde(n+i,T,1,0);
	for(ll x=1;x<=n;x++){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		for(ll i=1;i<=n;i++){
			ll tm=i-1;
			tm=min(c,tm);
			ll p=a-b*tm;
			if(p>0)v[x][i]=p;
		}
	}
	nx=ny=n;
//	maxcost_maxflow();
	KM();
}