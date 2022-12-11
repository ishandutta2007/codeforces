#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=2e3+20;

int n,k;

bitset<maxn>f[maxn]; int vis[maxn];
bitset<maxn>tmp[2];

int trans[maxn][2][2];

int op[3][2][2];

inline void insert(bitset<maxn>x)
{
    DREP(i,2*n-1,0)
	if(x[i])
	{
	    if(!vis[i]){ f[i]=x; vis[i]=1; return;}
	    else x^=f[i];
	}
    if(x[2*n])puts("NO"),exit(0);
}

int id[maxn];

inline void init()
{
    n=read();k=read();
    REP(i,0,n)trans[i][0][0]=trans[i][1][1]=1;
    op[0][1][0]=op[0][0][1]=1;
    op[1][0][0]=op[1][1][0]=op[1][1][1]=1;
    op[2][0][0]=op[2][0][1]=op[2][1][1]=1;
    REP(i,1,k)
    {
	string s;
	cin>>s;
	if(s!="mix")
	{
	    int t=0;
	    if(s=="RB")t=1;
	    else if(s=="YB")t=2;
	    int num=read();
	    while(num--)
	    {
		int id=read();id--;
		static int tmp[2][2];
		memset(tmp,0,sizeof(tmp));
		REP(a,0,1)REP(b,0,1)REP(c,0,1)
		    tmp[a][b]^=op[t][a][c]&trans[id][c][b];
		REP(a,0,1)REP(b,0,1)trans[id][a][b]=tmp[a][b];
	    }
	}else
	{
	    int num=read();
	    tmp[0].reset(); tmp[1].reset();
	    while(num--)
	    {
	    	int id=read(); id--;
	    	REP(op,0,1)
		{
		    REP(x,0,1)
		    {
			tmp[op][id<<1|x]=trans[id][op][x];
		    }
		}
	    }
	    char ch;
	    cin>>ch;
	    if(ch=='R' || ch=='B')tmp[0][n<<1]=1;
	    if(ch=='Y' || ch=='B')tmp[1][n<<1]=1;
	    insert(tmp[0]);
	    insert(tmp[1]);
	}
    }
    REP(i,0,2*n-1)
    {
	if(!vis[i])id[i]=0;
	else {
	    id[i]=f[i][2*n];
	    REP(j,0,i-1)if(f[i][j])
		id[i]^=f[i][j]&id[j];
	}
    }puts("YES");
    REP(i,0,n-1)
    {
	int a=id[i<<1],b=id[i<<1|1],t=a+b*2;
	if(t==0)printf(".");
	else if(t==1)printf("R");
	else if(t==2)printf("Y");
	else if(t==3)printf("B");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("639f.in","r",stdin);
    freopen("639f.out","w",stdout);
#endif
    init();
    return 0;
}