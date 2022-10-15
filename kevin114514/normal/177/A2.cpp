#include<bits/stdc++.h>
using namespace std;
bool B[110][110];
void init(int N)
{
    for(int i=0;i<N;i++)
        B[N/2][i]=B[i][N/2]=B[i][i]=B[i][N-i-1]=true;
    return ;
}
int main()
{
    int N,Ans=0;
    cin>>N;
    init(N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            int X;
            cin>>X;
            if(B[i][j])
                Ans+=X;
        }
    cout<<Ans<<endl;
    return 0;
}