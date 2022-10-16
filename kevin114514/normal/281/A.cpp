#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin>>S;
    if(islower(S[0]))
        S[0]-=('a'-'A');
    cout<<S<<endl;
    return 0;
}