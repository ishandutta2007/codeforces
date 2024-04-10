#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) //cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

long long n, k, x, ls1, ls2, m;

struct m11
{
	long long s1 = 0, s2 = 0;
	long long c[4][4];
	long long last = -1;
	long long first = -1;

	m11()
	{
		memset(c, 0, sizeof(c));
	}

}dp[66];

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> k >> x >> n >> m;


	dp[1].s1 = 1;
	dp[1].last = 1;
	dp[1].first = 1;

	dp[2].s2 = 1;
	dp[2].last = 2;
	dp[2].first = 2;

	for(long long i=3;i<=k;i++)
	{

		dp[i] = dp[i-2];
		dp[i].last = dp[i-1].last;
		dp[i].s1 += dp[i-1].s1;
		dp[i].s2 += dp[i-1].s2;
		dp[i].c[1][1] += dp[i-1].c[1][1];
		dp[i].c[1][2] += dp[i-1].c[1][2];
		dp[i].c[2][2] += dp[i-1].c[2][2];
		dp[i].c[2][1] += dp[i-1].c[2][1];
		dp[i].c[dp[i-2].last][dp[i-1].first]++;

	}

	m11 f=dp[k];

	long long p11 = 1;
	long long p12 = 2;
	long long p21 = 4;
	long long p22 = 8;

	long long st[] = {0, 1, 2, 4, 8, 15, 3, 5, 12, 10, 0, 0};

	for(long long i=0;(2*i)<=n;i++)
		for(long long j=0;(2*j) <= m;j++)
		{
			long long i1 = 2*i;
			long long j1 = 2*j;
			long long ans = i*f.s1 + j*f.s2;
			for(long long g = 0;g<10;g++)
			{
				dbg(st[g]);
				long long ans1 = ans;
				long long in1=0, in2=0, o1=0, o2=0;
				if((p11 & st[g])!=0) ans1 += f.c[1][1], in1++, o1++;
				if((p12 & st[g])!=0) ans1 += f.c[1][2], o1++, in2++;
				if((p22 & st[g])!=0) ans1 += f.c[2][2], o2++, in2++;
				if((p21 & st[g])!=0) ans1 += f.c[2][1], in1++, o2++;
				long long l1, l2;
				l1 = i1+(in1>0) + (o1>0);
				l2 = j1 + (in2>0) +(o2>0);
				if(ans1 == x && l1<=n && l2 <=m)
				{
					string s1, s2;
					if(in1) s1+='C';
					if(in2) s2+='C';
					for(long long gg = 1; gg<=i; gg++)
						s1+="AC";
					for(long long gg = 1; gg<=j; gg++)
						s2+="AC";
					for(long long gg = s1.size();gg<n;gg++)
						s1+='F';
					for(long long gg = s2.size();gg<m;gg++)
						s2+='F';
					if(o1) s1[s1.size()-1] = 'A';
					if(o2) s2[s2.size()-1] = 'A';
					cout << s1 << '\n'; 
					cout << s2 << '\n';
					return 0;
				}
			}

		}

		cout << "Happy new year!\n";
	return 0;
}