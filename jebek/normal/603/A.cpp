#include <iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

string s;
int ans,t,n;

int main()
{
    cin>>n>>s;
    ans=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
            t++;
        else
            ans++;
    }
    cout<<ans+min(t,2)<<endl;
}