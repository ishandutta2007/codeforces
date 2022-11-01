#include<bits/stdc++.h>
using namespace std;

set<string>s,se;
string t;
int n;

void print(){
  se.clear();
  while(s.size())
    {
      string tmp=*s.begin();
      s.erase(s.begin());
      cout<<tmp<<" ";
      se.insert(tmp);
    }
  s=se;
  cout<<endl;
}

int main()
{
  cin>>t;
  s.insert(t);
  cin>>t;
  s.insert(t);
  cin>>n;
  print();
  for(int i=0;i<n;i++)
    {
      cin>>t;
      s.erase(t);
      cin>>t;
      s.insert(t);
      print();
    }
}