#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define out(t,x) for(int i=0;i<(t);i++)cout<<(x)

int main()
{
   vector<string> v;
   char c;
   string s;
   bool toLeft=false;
   int maxlen=0;
   int k;
   v.push_back("");
   while(scanf("%c",&c)>0){
      if(c!='\n'){
         v[v.size()-1]+=c;
      }else{
         if(maxlen<v[v.size()-1].length()){
            maxlen=v[v.size()-1].length();
         }
         v.push_back("");
      }
   }
   v.erase(v.end()-1);
   out(maxlen+2,'*');
   cout << "\n";
   for(int i=0;i<v.size();i++){
      s = v[i];
      out(1,'*');
      k=(maxlen-s.length())/2;
      if((maxlen-s.length())%2){
         toLeft=!toLeft;
         if(toLeft){
            out(k,' ');
            cout << s;
            out(k+1,' ');
         }else{
            out(k+1,' ');
            cout << s;
            out(k,' ');
         }
      }else{
         out(k,' ');
         cout << s;
         out(k,' ');
      }
      out(1,'*');
      cout << "\n";
   }
   out(maxlen+2,'*');
	return 0;
}