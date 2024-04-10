#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
 
    bool isOK = false;

    for(int i=1; i<n; i++)
    {
       if((s[i]>='a') && (s[i]<='z')) {
          isOK = true; //     -   
          break;
       }
   }

    if (!isOK) { //  
      for(int i=0; i<n; i++)
        if((s[i]>='A') && (s[i]<='Z')) s[i]+='a'-'A'; else s[i]+='A'-'a';
    }
    cout<<s;
}