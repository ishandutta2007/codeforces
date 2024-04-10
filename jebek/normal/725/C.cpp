#include<bits/stdc++.h>
using namespace std;

string s;
int a[30];

int f(char c)
{
  return int(c-'A');
}

void print(int l,int r,int k)
{
  if(k==1){
    for(int i=l;i<r;i++)
      cout<<s[i];
  }
  else{
    for(int i=l;i>r;i--)
      cout<<s[i];
  }
}

int main()
{
  cin>>s;
  for(int i=1;i<s.size();i++)
    {
      if(a[f(s[i])]){
	int x=(i+a[f(s[i])]-2)/2;
	if(x<13){
	  print(x,-1,-1);
	  print(26,14+x,-1);
	  cout<<endl;
	  print(x+1,i,1);
	  print(i+1,15+x,1);
	  cout<<endl;
	}
	else{
	  print(x,x-13,-1);
	  cout<<endl;
	  print(x+1,i,1);
	  print(i+1,27,1);
	  print(0,x-12,1);
	  cout<<endl;
	}
	return 0;
      }
      a[f(s[i-1])]=i;
    }
  cout<<"Impossible\n";
}