#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0;
    int d=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='A')
        a++;
        else
        d++;
    }
    if(a>d)
       cout<<"Anton";
    if(a<d)
       cout<<"Danik";
    if(a==d)
       cout<<"Friendship";

}