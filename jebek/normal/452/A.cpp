#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

string s1[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string s;
int n;

bool check(int k)
{
    if(s1[k].size()!=n)
        return false;
    for(int i=0;i<n;i++)
        if(s[i]!='.' && s[i]!=s1[k][i])
            return false;
    return true;
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<8;i++)
    {
        if(check(i))
        {
            cout<<s1[i]<<endl;
            return 0;
        }
    }
}