
#include <iostream>
#include <string>
#include <algorithm>



using namespace std;

int main()
{
     string s1;
     string s2;
     cin>>s1>>s2;
     if(s1==s2)
       cout<<"-1";
     else
      {
          int t=max(s1.size(), s2.size());
          cout<<t;
      }
}