#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin>>S;
    int cnt=0;
    for(int i=0;i<S.length();i++)
        if(S[i]=='7'||S[i]=='4')
            cnt++;
    bool OK=cnt>0;
    while(cnt)
    {
        if(cnt%10!=7&&cnt%10!=4)
            OK=false;
        cnt/=10;
    }
    if(OK)
        puts("YES");
    else    puts("NO");
    return 0;
}