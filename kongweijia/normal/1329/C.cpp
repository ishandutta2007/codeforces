#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define infty 0x3f3f3f3f

#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

//head
const int maxn=(1<<21);
int a[maxn+5];
int b[maxn+5],POS[maxn+5];
int lg[maxn+5];

int main()
{
    lg[1]=1;
    rep(i,2,maxn) lg[i]=lg[i>>1]+1;

    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        int h,g; scanf("%d%d",&h,&g);
        int n=(1<<h)-1;
        ll sum=0;
        rep(i,1,n*2+1) a[i]=0;
        rep(i,1,n) scanf("%d",&a[i]),sum+=a[i];
        rep(i,1,n) b[i]=a[i],POS[a[i]]=i;
        sort(b+1,b+n+1);
        int cnt=0;
        VI ANS;
        per(i,1,n)
        {
            if(cnt==(1<<h)-(1<<g)) break;
            int x=b[i],pos=POS[x];
            int now=pos;
            while(a[now*2] || a[now*2+1])
            {
                if(a[now*2]>a[now*2+1]) now=now*2;
                else now=now*2+1;
            }
            if(now>=(1<<g))
            {
                cnt++;
                now=pos;
                sum-=x;
                ANS.pb(now);
                a[now]=0;
                POS[x]=0;
                while(a[now*2] || a[now*2+1])
                {
                    int nxt=-1;
                    if(a[now*2]>a[now*2+1]) nxt=now*2;
                    else nxt=now*2+1;
                    int X=a[nxt];
                    swap(a[now],a[nxt]);
                    POS[X]=now;
                    now=nxt;
                }
            }
        }
        printf("%lld\n",sum);
        assert((int)ANS.size()==(1<<h)-(1<<g));
        rep(i,1,(1<<h)-(1<<g)) printf("%d%c",ANS[i-1]," \n"[i==(1<<h)-(1<<g)]);
    }
    return 0;
}