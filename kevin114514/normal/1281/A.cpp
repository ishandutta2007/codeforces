#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        string S;
        cin>>S;
        reverse(S.begin(),S.end());
        if(S[0]=='u')
            puts("JAPANESE");
        else if(S[0]=='a')
            puts("KOREAN");
        else    puts("FILIPINO");
    }
    return 0;
}