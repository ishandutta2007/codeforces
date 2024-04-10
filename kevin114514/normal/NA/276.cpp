#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string A,B,C;
        cin>>A>>B>>C;
        bool OK=true;
        for(int i=0;i<A.length();i++)
            if(A[i]!=C[i]&&B[i]!=C[i])
                OK=false;
        if(OK)
            puts("YES");
        else    puts("NO");
    }
    return 0;
}