#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    string S;
    cin>>S;
    int Ans=0;
    for(int i=0;i<N-1;i++)
        if(S[i]=='S'&&S[i+1]=='F')
            Ans++;
        else if(S[i]!=S[i+1])
            Ans--;
    if(Ans>0)
        puts("YES");
    else    puts("NO");
    return 0;
}