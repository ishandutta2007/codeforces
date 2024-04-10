#include<bits/stdc++.h>
using namespace std;
int P[100],T[100];
int main()
{
    int N,C;
    cin>>N>>C;
    for(int i=0;i<N;i++)
        cin>>P[i];
    for(int i=0;i<N;i++)
        cin>>T[i];
    int L=0,R=0,t=0;
    for(int i=0;i<N;i++)
        t+=T[i],
        L+=max(0,P[i]-t*C);
    t=0;
    for(int i=N-1;i>=0;i--)
        t+=T[i],
        R+=max(0,P[i]-t*C);
    if(L==R)
        puts("Tie");
    else if(L>R)
        puts("Limak");
    else    puts("Radewoosh");
    return 0;
}