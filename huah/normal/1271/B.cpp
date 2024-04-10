#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin>>n>>s;
    int ans1=0,ans2=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='B') ans1++;
        else ans2++;
    if((ans1&1)&&(ans2&1)){cout<<-1;return 0;}
    if(!(ans2&1))
        for(int i=0;i<s.size();i++)
        if(s[i]=='W') s[i]='B';
    else s[i]='W';
    queue<int>q;
    for(int i=0;i<s.size()-1;i++)
        if(s[i]=='B')
        {
            q.push(i+1);
            if(s[i+1]=='W') s[i+1]='B';
            else s[i+1]='W';
        }
    cout<<q.size()<<endl;
    while(!q.empty())
        cout<<q.front()<<' ',q.pop();
}