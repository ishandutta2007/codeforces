#include <iostream>
#include <string>

using namespace std;

string s, sir;


int main()
{
cin>>s;
cin>>sir;
int ans=0;
for(int i=0;i+sir.size()<=s.size();i++)
{
    string cand=s.substr(i, sir.size());
    if(cand==sir)
        s[i+sir.size()-1]='#', ans++;
    //cout<<s<<'\n';
}
cout<<ans<<'\n';
    return 0;
}