#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;

long long n, k;
long long g[] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
long long lg = 20;

bool isPrime(long long k)
{
	for(long long i=2;i*i <=k; i++)
	{
		if(k%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;

	if(isPrime(n))
	{
		cout << 1;
		return 0;
	}
	if(n%2 == 0)
		cout << 2;
	else 
	{
		if(isPrime(n-2)) 
			cout << 2;
		else
			cout << 3;
	}

	return 0;
}