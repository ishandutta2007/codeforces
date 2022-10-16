#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1045

using namespace std;

int f[DMAX], f2[DMAX], n, k, x, m=100000, M, e;

int main()
{
	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &x);

	for(int i=1;i<=n;i++)
	{
		scanf("%d", &e);
		f[e]++;
	}

	for(int i=1;i<=k;i++)
	{
		int off = 1;

		for(int j=0;j<1040;j++)
		{
			if(f[j]==0) 
				continue;
			int p = j^x;
			f2[j^x] += (f[j]+off)/2;
			f2[j] += (f[j]+1-off)/2;
			if(f[j]%2 == 1) 
				off = 1 - off;
		}
		memcpy(f, f2, sizeof(f));
		memset(f2, 0, sizeof(f2));
	}

//	dbg_v(f, 15);

	for(int i=0;i<1040;i++)
	{
		if(f[i]>0) m = min(m, i), M=i;
	}
	//cout << M << ' ' << m << '\n';
	printf("%d %d\n", M, m);
}