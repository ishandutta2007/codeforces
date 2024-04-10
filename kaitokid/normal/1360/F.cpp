#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,m;
string s[12];
bool ch(string x)
{
    for(int i=1;i<n;i++)
    {
        int d=0;
        for(int j=0;j<m;j++)
            if(x[j]!=s[i][j])d++;
        if(d>1)return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    cin>>n>>m;
for(int i=0;i<n;i++)cin>>s[i];
bool no=true;
for(int i=0;i<m;i++){
        if(!no)break;
for(int j='a';j<='z';j++)
{

    string u=s[0];
   u[i]=char(j);
   if(ch(u)){cout<<u<<endl;no=false;break;}
}

}
if(no)cout<<-1<<endl;
}

    return 0;
}