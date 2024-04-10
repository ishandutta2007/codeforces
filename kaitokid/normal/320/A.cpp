#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s;
   cin>>s;
   int i=0;
   while(i<s.size())
   {if(s[i]=='1'&&s[i+1]=='4'&&s[i+2]=='4'){i+=3;continue;}
   if(s[i]=='1'&&s[i+1]=='4'){i+=2;continue;}
   if(s[i]=='1'){i+=1;continue;}
   cout<<"NO";return 0;

   }
   cout<<"YES";
    return 0;
}