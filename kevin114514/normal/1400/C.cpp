#include<bits/stdc++.h>
using namespace std;
int must0[100100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(must0,false,sizeof(must0));
        string S;
        cin>>S;
        int x;
        cin>>x;
        for(int i=0;i<S.length();i++)
            if(S[i]=='0')
            {
                if(i-x>=0)
                    must0[i-x]=true;
                if(i+x<S.length())
                    must0[i+x]=true;
            }
        bool OK=true;
        for(int i=0;i<S.length();i++)
            if(S[i]=='1')
            {
                bool flag=false;
                if(i-x>=0&&!must0[i-x])
                    flag=true;
                if(i+x<S.length()&&!must0[i+x])
                    flag=true;
                if(!flag)
                    OK=false;
            }
        if(!OK)
            puts("-1");
        else
        {
            for(int i=0;i<S.length();i++)
                if(must0[i])
                    cout<<0;
                else    cout<<1;
            puts("");
        }
    }
    return 0;
}