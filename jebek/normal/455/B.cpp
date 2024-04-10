#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

typedef pair<int,string> pii;
int n,k;
set<pii>s;
map<string,bool>dp,dp1,mark;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        s.insert(pii(s1.size(),s1));
    }
    while(s.size())
    {
        string s1=(--s.end())->second;
        s.erase(--s.end());
        if(!mark[s1])
            dp1[s1]=true;
       // cout<<s1<<" "<<dp[s1]<<" "<<dp1[s1]<<" "<<mark[s1]<<endl;
        string s2=s1;
        s1.resize(s1.size()-1);
        mark[s1]=true;
        if(!dp[s2])
            dp[s1]=true;
        if(!dp1[s2])
            dp1[s1]=true;
        if(s1.size()!=0)
            s.insert(pii(s1.size(),s1));
    }
    string s1="";
  //  cout<<s1<<" "<<dp[s1]<<" "<<dp1[s1]<<" "<<mark[s1]<<endl;
    if((dp1[s1] && dp[s1]) || (dp[s1] && k%2==1))
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}