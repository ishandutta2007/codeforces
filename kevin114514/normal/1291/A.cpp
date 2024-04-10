#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        string S;
        cin>>N>>S;
        char Ans[3]="xx";
        int p=0,i=0;
        while(i<N&&p<2)
        {
            if((S[i]-'0')%2==1)
                Ans[p++]=S[i];
            i++;
        }
        if(Ans[1]=='x')
            puts("-1");
        else    puts(Ans);   
    }
    return 0;
}