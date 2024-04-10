#include <iostream>
#include<string>

using namespace std;

string s,t;

int main()
{
    cin>>s>>t;
    int p=s.size()-1;
    while(s[p]=='z')
    {
        s[p]='a';
        p--;
    }
    s[p]=char(int(s[p])+1);
    if(s==t)
        cout<<"No such string"<<endl;
    else
        cout<<s<<endl;
}