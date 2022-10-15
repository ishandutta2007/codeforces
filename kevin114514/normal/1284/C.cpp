#include<bits/stdc++.h>
using namespace std;
long long fact[252500];
void Get_F(int Mod)
{
	fact[0]=1;
	for(long long i=1;i<251000;i++)
		fact[i]=fact[i-1]*i%Mod;
	return ;
}
inline long long Count(int N,int i,int Mod)
{
	return (N-i)*fact[i+1]%Mod*fact[N-i-1]%Mod*(N-i)%Mod;
}
int main()
{
	int N,Mod;
	cin>>N>>Mod;
	Get_F(Mod);
	long long ans=0;
	for(int i=0;i<N;i++)
		ans=(Count(N,i,Mod)+ans)%Mod;
	cout<<ans<<endl;
	return 0;
}