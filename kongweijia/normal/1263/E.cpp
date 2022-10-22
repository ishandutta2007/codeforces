#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define MAXN 1000000
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

int sum;
//head
struct segt
{
    #define ls i*2
    #define rs i*2+1
    int a[MAXN*4+5],b[MAXN*4+5],lz[MAXN*4+5];
    void pu(int i) {a[i]=min(a[ls],a[rs]); b[i]=max(b[ls],b[rs]);}
    void push(int i,int x) {a[i]+=x; b[i]+=x; lz[i]+=x;}
    void pd(int i)
    {
        push(ls,lz[i]);
        push(rs,lz[i]);
        lz[i]=0;
    }
    void add(int i,int l,int r,int ql,int qr,int x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,x);
            return;
        }
        if(r<ql || qr<l) return;
        pd(i);
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    int ask()
    {
        if(sum==0 && a[1]>=0) return b[1];
        else return -1;
    }
}t;

char s[MAXN+5];
char buff[MAXN+5];

int main()
{
	int n; scanf("%d",&n);
	int ptr=1;
	scanf("%s",s+1);
    rep(i,1,n)
    {
        if(s[i]=='L') ptr=max(1,ptr-1);
        else if(s[i]=='R') ptr++;
        else
        {
            if(buff[ptr]=='(') t.add(1,1,n,ptr,n,-1),sum--;
            if(buff[ptr]==')') t.add(1,1,n,ptr,n,1),sum++;
            buff[ptr]=s[i];
            if(buff[ptr]=='(') t.add(1,1,n,ptr,n,1),sum++;
            if(buff[ptr]==')') t.add(1,1,n,ptr,n,-1),sum--;
        }
        printf("%d%c",t.ask()," \n"[i==n]);
    }
	return 0;
}