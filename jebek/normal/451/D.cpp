#include <iostream>
#include<string>

using namespace std;

string s;
long long ans1,ans2,t[3][3];

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int k=int(s[i]-'a');
        t[k][i%2]++;
        ans1+=t[k][1-i%2];
        ans2+=t[k][i%2];
    }
    cout<<ans1<<" "<<ans2<<endl;
}