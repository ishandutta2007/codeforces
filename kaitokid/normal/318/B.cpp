#include <iostream>

using namespace std;

int main()
{
   string s;
   cin>>s;
   unsigned long long n=0 ,res=0;
   for(unsigned long long i=0;i<s.size();i++)
   {if(s[i]=='h'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='y'){n++;i+=4;}
    if(s[i]=='m'&&s[i+1]=='e'&&s[i+2]=='t'&&s[i+3]=='a'&&s[i+4]=='l'){res+=n;i+=4;}
   }
   cout<<res;
    return 0;
}