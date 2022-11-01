#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string s;
int a;

int main()
{
  cin>>s;
  if(s[0]=='4')
    {
      cout<<"NO"<<endl;
      return 0;
    }
  for(int i=0;i<s.size();i++)
    {
      int k=int(s[i]-'0');
      if(k!=4)
	{
	  a=0;
	  if(k!=1)
	    {
	      cout<<"NO"<<endl;
	      return 0;
	    }
	}
      else
	a++;
      if(a>2)
	{
	  cout<<"NO"<<endl;
	  return 0;
	}
    }
  cout<<"YES"<<endl;
}