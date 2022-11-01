#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int n;
  cin>>n;
  printf("%s %s\n",s1.c_str(),s2.c_str());
  while(n--){
    string s3,s4;
    cin>>s3>>s4;
    if(s1==s3){
      s1=s4;
    }
    else{
      s2=s4;
    }
    printf("%s %s\n",s1.c_str(),s2.c_str());
  }
  return 0;
}