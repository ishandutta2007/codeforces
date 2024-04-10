#include<bits/stdc++.h>
using namespace std;
int Num[200200][2];
int Add[200200];
long long GCD(long long A,long long B)
{
	if(B==0)
		return A;
	return GCD(B,A%B);
}
int main()
{
    long long Ans=1;
    int N;
    cin>>N;
    if(N==2)
    {
    	long long A,B;
    	cin>>A>>B;
    	cout<<A*B/GCD(A,B)<<endl;
    	return 0;
	}
    for(int i=0;i<200200;i++)
        for(int j=0;j<2;j++)
            Num[i][j]=100000000;
    for(int i=0;i<N;i++)
    {
        int X;
        cin>>X;
        int X1=X;
        for(int j=2;j<=sqrt(X1);j++)
        {
            int Cnt=0;
            while(X%j==0)
            {
                Cnt++;
                X/=j;
            }
            if(Cnt==0)
            	continue;
            if(Cnt<Num[j][0])
            {
                Num[j][1]=Num[j][0];
                Num[j][0]=Cnt;
            }
            else if(Cnt<Num[j][1])
                Num[j][1]=Cnt;
            if(Cnt>0)
          		Add[j]++;
          	if(j==5)
          	{
          		//cout<<i<<endl;
			}
            if(j==2)
            {
            	//cout<<i<<" "<<Num[2][0]<<" "<<Num[2][1]<<endl;
			}
        }
        if(X>1)
        {
            if(1<Num[X][0])
            {
                Num[X][1]=Num[X][0];
                Num[X][0]=1;
            }
            else if(1<Num[X][1])
                Num[X][1]=1;
            Add[X]++;
        }
    }
    for(int i=0;i<200200;i++)
        for(int j=0;j<2;j++)
            if(Num[i][j]==100000000)
                Num[i][j]=0;
    //cout<<Num[2][0]<<" "<<Num[2][1]<<endl;
	//cout<<Add[5]<<endl;
    for(int i=0;i<200200;i++)
    	if(N-Add[i]<2)
   	    	for(int j=0;j<Num[i][2-N+Add[i]-1];j++)
            	Ans*=i;
    cout<<Ans<<endl;
    return 0;
}