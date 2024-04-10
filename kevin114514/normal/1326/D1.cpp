#include<bits/stdc++.h>
using namespace std;
string LPOSP(string S)
{
    for(int i=S.length();i>=1;i--)
    {
        string T=S.substr(0,i);
        string U=T;
        reverse(U.begin(),U.end());
        if(U==T)
            return T;
        T=S.substr(S.length()-i,i);
        U=T;
        reverse(U.begin(),U.end());
        if(U==T)
            return T;
    }
    return "";
}
string LPSP(string S)
{
    for(int i=0;i<S.length()/2;i++)
        if(S[i]!=S[S.length()-i-1])
        {
            string Ans;
            for(int j=0;j<i;j++)
                Ans+=S[j];
            Ans+=LPOSP(S.substr(i,S.length()-i-i));
            for(int j=S.length()-i;j<S.length();j++)
                Ans+=S[j];
            return Ans;
        }
    return S;
}
int main()
{
    int X;
    cin>>X;
    while(X--)
    {
        string S;
        cin>>S;
        cout<<LPSP(S)<<endl;
    }
    return 0;
}