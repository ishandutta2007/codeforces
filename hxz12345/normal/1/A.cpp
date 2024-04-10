#include<bits/stdc++.h>
using namespace std;
long long n,m,a;
int main()
{
	cin>>n>>m>>a;
	cout<<(long long)(ceil(n/(double)a)*ceil(m/(double)a));
	return 0;
}