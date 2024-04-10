#include<bits/stdc++.h>
using namespace std;
int main()
{
    int last=0;
    cin>>last;
    string S;
    cin>>S;
    int cnt=0;
    last=0;
    for(int i=0;i<S.length();i++)
        if(S[i]!=S[last])
        {
            cnt+=i-last-1;
            last=i;
        }
    cnt+=S.length()-last-1;
    cout<<cnt<<endl;
    return 0;
}