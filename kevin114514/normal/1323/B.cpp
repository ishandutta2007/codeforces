#include<bits/stdc++.h>
using namespace std;
int A[100100],B[100100];
long long Ans;
int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int j=0;j<M;j++)
        cin>>B[j];
    for(int i=1;i<=N;i++)
        if(i*M>=K&&K%i==0)
        {
            int j=K/i;
            long long a=0,b=0;
            int ca=0,cb=0;
            for(int k=0;k<N;k++)
                if(A[k])
                    ca++;
                else
                {
                    a+=max(0,ca-i+1);
                    ca=0;
                }
            a+=max(0,ca-i+1);
            for(int k=0;k<M;k++)
                if(B[k])
                    cb++;
                else
                {
                    b+=max(0,cb-j+1);
                    cb=0;
                }
            b+=max(0,cb-j+1);
            Ans+=a*b;
        }
    cout<<Ans<<endl;
    return 0;
}