#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin>>S;
    int Cnt=0;
    for(int i=0;i<S.length();i++)
        if(S[i]=='a')
            Cnt+=2;
    cout<<min(Cnt-1,(int)(S.length()))<<endl;
    return 0;
}