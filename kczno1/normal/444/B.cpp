#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5;
bitset<N>have,b;
int n,ans[N],a[N];

void initAB() {
	int i,d;s64 x;
	cin>>n>>d>>x;
	auto getNextX=[&]()->int 
	{
  		x = (x * 37 + 10007) % 1000000007;
    	return x;
	};
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    static int b[N];
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
    rep(i,0,n-1)::b[i]=b[i];
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	initAB();
	static int na[N];
	rep(i,0,n-1)na[a[i]]=i;
	per(v,n,1)
	{
//		cerr<<na[v]<<endl;
		bitset<N>now=(b<<na[v])&~have;
		for(int i=-1;(i=now._Find_next(i))<n;)
		{
//			cerr<<i<<endl;
			have[i]=1;
			ans[i]=v;
		}
	}
	rep(i,0,n-1)printf("%d\n",ans[i]);
}