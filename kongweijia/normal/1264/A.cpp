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

const int maxn=400000;

//head
int a[maxn+5];
int c[maxn+5];

int main()
{
	int CAS; scanf("%d",&CAS);
	while(CAS--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        a[0]=-1;
        int N=0;
        rep(i,1,n)
        {
            if(a[i]!=a[i-1]) c[++N]=1;
            else c[N]++;
        }
        int g=c[1],s=0,b=0;
        rep(i,2,N)
        {
            if(s<=g) s+=c[i];
            else if(g+s+b+c[i]<=n/2) b+=c[i];
            else break;
        }
        if(g<s && g<b && 2*(g+s+b)<=n) printf("%d %d %d\n",g,s,b);
        else puts("0 0 0");
    }
    return 0;
}