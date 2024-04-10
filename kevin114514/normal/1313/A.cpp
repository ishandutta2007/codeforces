#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int A[3],Ans=0;
        cin>>A[0]>>A[1]>>A[2];
        sort(A,A+3);
        reverse(A,A+3);
        for(int i=0;i<3;i++)
            if(A[i])
            {
                A[i]--;
                Ans++;
            }
        if(A[0]&&A[1])
        {
            A[0]--;
            A[1]--;
            Ans++;
        }
        if(A[0]&&A[2])
        {
            A[0]--;
            A[2]--;
            Ans++;
        }
        if(A[1]&&A[2])
        {
            A[1]--;
            A[2]--;
            Ans++;
        }
        if(A[0]&&A[1]&&A[2])
            Ans++;
        cout<<Ans<<endl;
    }
    return 0;
}