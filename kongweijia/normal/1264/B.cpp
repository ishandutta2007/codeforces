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

const int maxn=100000;

//head
bool cal(int n,int s,VI m,VI &res)
{
    if(m[s]==0) return 0;
    m[s]--; res.pb(s);
    rep(i,2,n)
    {
        if(res.back()==0)
        {
            if(--m[1]<0) return 0;
            res.pb(1);
        }
        else if(res.back()==3)
        {
            if(--m[2]<0) return 0;
            res.pb(2);
        }
        else if(res.back()==1)
        {
            if(m[0])
            {
                m[0]--;
                res.pb(0);
            }
            else if(m[2])
            {
                m[2]--;
                res.pb(2);
            }
            else return 0;
        }
        else
        {
            if(m[3])
            {
                m[3]--;
                res.pb(3);
            }
            else if(m[1])
            {
                m[1]--;
                res.pb(1);
            }
            else return 0;
        }
    }
    return 1;
}

int main()
{
	int n=0;
	VI m;
	rep(i,0,3)
	{
        int x; scanf("%d",&x); n+=x;
        m.pb(x);
	}
	rep(i,0,3)
	{
        VI res;
        if(cal(n,i,m,res))
        {
            puts("YES");
            rep(i,0,n-1) printf("%d%c",res[i]," \n"[i==n-1]);
            return 0;
        }
	}
	puts("NO");
    return 0;
}