#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S1,S2;
    cin>>S1>>S2;
    cout<<max(abs(S1[0]-S2[0]),abs(S1[1]-S2[1]))<<endl;
    while(S1!=S2)
    {
        string op;
        if(S1[0]>S2[0])
            op+='L',
            S1[0]--;
        if(S1[0]<S2[0])
            op+='R',
            S1[0]++;
        if(S1[1]<S2[1])
            op+='U',
            S1[1]++;
        if(S1[1]>S2[1])
            op+='D',
            S1[1]--;
        cout<<op<<endl;
    }
    return 0;
}