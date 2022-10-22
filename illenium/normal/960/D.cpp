#include<bits/stdc++.h>
#define L 64
using namespace std;
typedef long long ll;
int q,op,be;
ll x,y,sh[L];

inline void shift(int fl,ll val)
{
	register ll mod=1LL<<fl;
	val%=mod;
	sh[fl]=(sh[fl]+val+mod)%mod;
}

int main()
{
    scanf("%d",&q);
    while(q--)
	{
		scanf("%d%lld",&op,&x);
		for(be=0;x>>be;be++);be--;
		if(op<3)
		{
            scanf("%lld",&y);
            if(op>1) shift(be,y);
            else shift(be,y),shift(be+1,-y*2);
		}
		else
		{
			for(;be>=0;be--)
			{
				printf("%lld ",x);
				x+=sh[be];
				if(x>=(1LL<<be+1))x-=(1LL<<be);
				x>>=1;
			}
			puts("");
		}
	}
}