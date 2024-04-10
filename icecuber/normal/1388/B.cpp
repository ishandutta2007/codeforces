#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  long long n,h,i,j,t,m,l,r,q;
  long long p=0,k,w,z,x,y,d;
  string s="",st="",s1="",s2="";
  cin >> q;
  for(l=0;l<q;l++)
    {
      s="";
      std::cin >> n;
      if(n%4!=0)
	p=n/4+1;
      else p=n/4;
      for(i=0;i<n-p;i++)
	s=s+'9';
      for(;i<n;i++)
	s=s+'8';
      std::cout << s << std::endl;
    }
  return 0;
}