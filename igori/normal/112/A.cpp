#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    for(int i=0; i<n; i++)
    {
        if(s1[i]<='Z')
          {
              s1[i]=s1[i]+'a'-'A';
          }
        if(s2[i]<='Z')
           s2[i]=s2[i]+'a'-'A';
    }
    if(s2>s1)
    cout<<"-1";
    if(s2<s1)
    cout<<"1";
    if(s2==s1)
    cout<<"0";

}