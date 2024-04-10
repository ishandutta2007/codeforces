#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        int tot=0;
        int totB=0;
        for(int i=0;i<S.length();i++)
            if(S[i]=='A')
                tot++;
            else
            {
                if(tot)
                    tot--;
                else    totB++;
            }
        cout<<totB%2+tot<<endl;
    }
    return 0;
}