#include<bits/stdc++.h>
using namespace std;
int A[5050];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        bool f=false;
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++)
            for(int j=i+2;j<N;j++)
                if(A[i]==A[j])
                    f=true;
        if(f)
            puts("YES");
        else    puts("NO");
    }
    return 0;
}