#include <iostream>
#include<string>

using namespace std;
long long ans,a[10];
string s;

int main()
{
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        ans+=a[int(s[i]-'0')];
    }
    cout<<ans<<endl;
}