#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ans;
string s;
int main()
{
  cin>>s;
  for(int i=0;i<s.size();i++)
    {
      if(isdigit(s[i]))
	{
	  int tmp=int(s[i]-'0');
	  ans+=(tmp%2==1);
	}
      else
	{
	  if(s[i]=='a' || s[i]=='o' || s[i]=='i' || s[i]=='e' || s[i]=='u')
	    ans++;
	}
    }
  cout<<ans<<endl;
}