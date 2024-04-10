#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin>>S;
    string ans="NO";
    for(int i=0;i<5;i++)
    {
        string T;
        cin>>T;
        for(int j=0;j<2;j++)
            if(T[j]==S[j])
                ans="YES";
    }
    cout<<ans<<endl;
    return 0;
}