#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,N;
    cin>>N;
    string S;
    cin>>S;
    i=0;
    int ii=1;
    while(i<S.length())
    {
        cout<<S[i];
        i+=ii;
        ii++;
    }
    return 0;
}