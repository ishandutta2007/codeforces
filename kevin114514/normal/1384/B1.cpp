#include<bits/stdc++.h>
using namespace std;
int DP[110][220];
int D[110];
int Delta(int K,int Now)
{
	if(Now<K)
		return Now;
	return K+K-Now;
}
void Solve()
{
	memset(DP,0,sizeof(DP));
	int N,K,L;
	cin>>N>>K>>L;
	for(int i=1;i<=N;i++)
		cin>>D[i];
	D[0]=-10000;
	DP[0][0]=true;
	for(int i=0;i<N;i++)
		for(int Time=0;Time<K+K;Time++)
			if(DP[i][Time])
				for(int NewTime=Time+1;NewTime<Time+K+K+1;NewTime++)
				{
					if(D[i+1]+Delta(K,NewTime%(K+K))<=L)
						DP[i+1][NewTime%(K+K)]=true;
					if(D[i]+Delta(K,NewTime%(K+K))>L)
						break;
				}
	bool OK=false;
	for(int i=0;i<K+K;i++)
		if(DP[N][i])
			OK=true;
	if(OK)
		puts("YES");
	else	puts("NO");
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Solve();
	return 0;
}