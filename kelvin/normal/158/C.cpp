#include <iostream>
#include <string>
#include <vector>
#define MAXL 300

using namespace std;

int main(void)
{
   int qn;
   string cmd,str;
   vector<string> pa;
   cin >> qn;
   while(qn--) {
      cin >> cmd;
      if(cmd[0]=='p') { // pwd
         for(int i=0;i<pa.size();i++)
            cout << '/' << pa[i];
         cout << '/' << endl;
      } else { // cd
         cin >> str;
         if(str[0]=='/') {
            pa.clear();
            str=str.substr(1);
         }
         int x=0;
         while(x<str.length()) {
            int nx=str.find_first_of('/',x);
            if(nx==string::npos) nx=str.length();
            string s=str.substr(x,nx-x);
            if(s=="..") pa.pop_back();
            else pa.push_back(s);
            x=nx+1;
         }
      }
   }
   return 0;
}