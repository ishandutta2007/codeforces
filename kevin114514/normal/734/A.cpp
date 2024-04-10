#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int Ans=0;
    string S;
    cin>>S;
    while(N--)
        if(S[N]=='A')
            Ans++;
        else    Ans--;
    if(Ans==0)
        puts("Friendship");
    else if(Ans>0)
        puts("Anton");
    else if(Ans<0)
        puts("Danik");
    return 0;
}