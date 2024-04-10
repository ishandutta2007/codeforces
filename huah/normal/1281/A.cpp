#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        if(s[s.size()-2]=='p'&&s[s.size()-1]=='o')
            cout<<"FILIPINO"<<endl;
        else if(s[s.size()-5]=='m'&&s[s.size()-4]=='n'&&s[s.size()-3]=='i'&&s[s.size()-2]=='d'&&s[s.size()-1]=='a')
            cout<<"KOREAN"<<endl;
        else cout<<"JAPANESE"<<endl;
    }
}