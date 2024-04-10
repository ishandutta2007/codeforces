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
        if(S.length()<=10)
            puts(S.c_str());
        else    cout<<S[0]<<S.length()-2<<S[S.length()-1]<<endl;
    }
    return 0;
}