#include <stdio.h>
#include <vector>
#define MOD 998244353
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

int a,b,start;
int z[40];
long long int ans[60];
int y[200010][60];
void swap(int s, int t)
{
	for(int j=0;j<=53;j++)
	{
		int k = y[s][j];
		y[s][j] = y[t][j];
		y[t][j] = k;
	}
}
void func1(int k)
{
	if(k==start)
	{
		int sum = 0;
		for(int j=0;j<b;j++) sum += z[j]%2;
		ans[sum]++;
		return;
	}
	
	func1(k+1);
	for(int j=0;j<b;j++) z[j] += y[k][j];
	func1(k+1);
	for(int j=0;j<b;j++) z[j] -= y[k][j];
}
int diff(long long int a, long long int b)
{
	int sum = 0;
	while(a>0||b>0)
	{
		if(b%2==1)
		{
			if(a%2==0) sum++;
			else sum--;
		}
		b/=2,a/=2;
	}
	return sum;
}

std::vector<int> V;
long long int S[20010][40],T[20010][40];
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int c;
		scanf("%lld",&c);
		for(int j=0;j<b;j++)
		{
			y[i][j] = c%2;
			c/=2;
		}
	}
	
	start = 1;
	for(int j=0;j<b;j++)
	{
		int p = -1;
		for(int i=start;i<=a;i++)
		{
			if(y[i][j]==1)
			{
				p = i;
				break;
			}
		}
		if(p==-1)
		{
			V.push_back(j);
			continue;
		}
		if(p!=start) swap(p,start);
		
		for(int i=1;i<=a;i++)
		{
			if(i==start) continue;
			if(y[i][j]==1) for(int k=0;k<b;k++) y[i][k] += y[start][k], y[i][k]%=2;
		}
		start++;
	}
	long long int M = power(2,a-start+1);
	
	if(start-1<=21)
	{
		func1(1);
		for(int j=0;j<=b;j++) ans[j]*=M, ans[j]%=MOD;
		for(int j=0;j<=b;j++) printf("%lld ",ans[j]);
		return 0;
	}
	else
	{
		int s = 0;
		for(int i=0;i<V.size();i++)
		{
			s*=2;
			s++;
		}
		S[0][0] = 1;
		
		for(int i=start-1;i>=1;i--)
		{
			int t = 0;
			for(int j=0;j<V.size();j++)
			{
				t*=2;
				t+=y[i][V[j]];
			}
			
			for(int j=0;j<=s;j++) for(int k=0;k<=b;k++) T[j][k] = 0;
			for(int j=0;j<=s;j++)
			{
				int d = diff(j,t)+1;
				for(int k=0;k<=b;k++) if(k+d>=0) T[j^t][k+d] += S[j][k], T[j^t][k+d]%=MOD;
				for(int k=0;k<=b;k++) T[j][k] += S[j][k], T[j][k]%=MOD;
			}
			for(int j=0;j<=s;j++) for(int k=0;k<=b;k++) S[j][k] = T[j][k];
		}
		
		for(int j=0;j<=s;j++) for(int k=0;k<=b;k++) ans[k] += S[j][k], ans[k]%=MOD;
		for(int k=0;k<=b;k++) ans[k] *= M, ans[k]%=MOD;
		for(int j=0;j<=b;j++) printf("%lld ",ans[j]);
		return 0;
	}
}