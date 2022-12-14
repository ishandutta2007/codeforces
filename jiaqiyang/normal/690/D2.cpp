#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int M=1000003;
int n,C;

int fc(int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
		s=(LL)s*i%M;
	return s;
}

int pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(LL)a*a%M)
		if(b&1)s=(LL)s*a%M;
	return s;
}

int co(int n,int k)
{
	if(k<0||k>n)return 0;
	return (LL)fc(n)*pow(fc(k),M-2)%M*pow(fc(n-k),M-2)%M;
}

int main()
{
	//n->C+1
	cin>>n>>C;
	cout<<(co(n+C,C)+M-1)%M<<endl;
	return 0;
}