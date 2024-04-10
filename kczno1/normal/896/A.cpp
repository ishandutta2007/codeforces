//# pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}

template<typename T>
struct vec
{
T *a;
int n;
void push_back(const T &x)
{
    if((n&-n)==n)//a=(T*)realloc(a,(n*2+1)*sizeof(T));
    {
        T *_a=new T [n*2+1];
        memcpy(_a,a,n*sizeof(T));
        a=_a;
    }
    a[n++]=x;
}
};

const int N=1e5+5;const ll inf=1e18+1;
const char A='"';
const char s0[]="What are you doing at the end of the world? Are you busy? Will you save us?"; 
const char qian[]=
"What are you doing while sending \"";
const char zhong[]=
"\"? Are you busy? Will you send \"";
const char hou[]=
"\"?";
ll len[N];

char F(int n,ll k)
{
	if(!n) return s0[k-1];
	if(k<=strlen(qian))return qian[k-1];
	k-=strlen(qian);
	if(k<=len[n-1]) return F(n-1,k);
	k-=len[n-1];
	if(k<=strlen(zhong))return zhong[k-1];
	k-=strlen(zhong);
	if(k<=len[n-1]) return F(n-1,k);
	k-=len[n-1];
	return hou[k-1];
}

int main()
{
    //freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    int tt;
    cin>>tt;
    len[0]=strlen(s0);
    rep(i,1,N-1)len[i]=min(inf,len[i-1]*2+(ll)(strlen(qian)+strlen(zhong)+strlen(hou)));
    while(tt--)
    {
    	int n;ll k;
    	cin>>n>>k;
    	if(k>len[n]) cout<<'.';
    	else cout<<F(n,k);
    }
}