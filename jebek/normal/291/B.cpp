#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='"')
      {
          cout<<"<";
          i++;
          while(s[i]!='"')
          {
              cout<<s[i];
              i++;
          }

          cout<<">"<<endl;
      }
      else if(s[i]!=' ')
      {
          cout<<"<";
          cout<<s[i];
          i++;
          while((s[i]!=' ')&&(i<s.size()))
          {
              cout<<s[i];
              i++;
          }
          cout<<">"<<endl;
      }
    }
}