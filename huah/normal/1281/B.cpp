#include<bits/stdc++.h>
using namespace std;
int T;
string s,t;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>s>>t;
        if(s<t) cout<<s<<endl;
        else
        {
            bool flag=false;
            for(int i=0;i<s.size()&&!flag;i++)
                for(int j=i+1;j<s.size()&&!flag;j++)
            {
                if(s[i]==s[j]||s[j]>t[i]) continue;
                swap(s[i],s[j]);
                if(s<t)
                {
                    flag=true;
                    cout<<s<<endl;
                    break;
                }
                swap(s[i],s[j]);
            }
            if(!flag) cout<<"---"<<endl;
        }
    }
}