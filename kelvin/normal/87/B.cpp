#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#define MAXN 120
#define MAXL 300

using namespace std;

const int inf=100000000;

int main(void)
{
   int qn;
   string cmd,arg,var,sub;
   int rf,pt,mid,i,j,x;
   map<string,int> mp;
   scanf("%d",&qn);
   while(qn--) {
      cin >> cmd;
      if(cmd=="typedef") {
         cin >> arg >> var;
      } else {
         cin >> arg;
      }
      for(i=0;i<arg.length()&&arg[i]=='&';i++);
      for(j=i;j<arg.length()&&arg[j]!='*';j++);
      sub=arg.substr(i,j-i);
      if(sub=="void") mid=0;
      else if(sub=="errtype") mid=-inf;
      else if(mp.find(sub)==mp.end()) mid=-inf;
      else mid=mp[sub];
      rf=i;
      pt=arg.length()-j;
      x=mid+pt-rf;
      if(x<0) x=-inf;
      if(cmd=="typedef") {
         mp[var]=x;
      } else {
         if(x<0) cout << "errtype" << endl;
         else {
            cout << "void";
            for(i=0;i<x;i++)
               cout << "*";
            cout << endl;
         }
      }
   }
   return 0;
}