#include<bits/stdc++.h>
using namespace std;
int X[4000];
int Mx[4000];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,K;
        cin>>N>>M>>K;
        for(int i=0;i<N;i++)
        	cin>>X[i];
        M--;
        K=min(M,K);
        K=M-K;
        M=N-M;
        for(int i=0;i<=N-M;i++)
        	Mx[i]=max(X[i],X[i+M-1]);
        int Ans=-1;
    	for(int i=0;i<=N-M-K;i++)
    	{
    		int Mn=1010101010;
    		for(int j=i;j<=i+K;j++)
    			Mn=min(Mn,Mx[j]);
    		Ans=max(Ans,Mn);
		}
		cout<<Ans<<endl;
    }
    return 0;
}