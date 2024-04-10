#include<bits/stdc++.h>
using namespace std;
double d[100100],f[100100],u[100100];
long double sum;
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>d[i],
		f[i]=floor(d[i]),
		u[i]=(f[i]==d[i]?f[i]:f[i]+1);
	for(int i=0;i<N;i++)
		sum+=f[i];
	sum=0-sum;
	for(int i=0;i<N;i++)
		if(sum<=0||f[i]==u[i])
			cout<<f[i]<<" ";
		else
			cout<<u[i]<<" ",
			sum--;
	puts("");
	return 0;
}