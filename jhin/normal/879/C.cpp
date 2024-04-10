#include <bits/stdc++.h>

using namespace std;

int a,b,c=1023,n,num;char x;
int main()
{ ios_base::sync_with_stdio(false);cin.tie(0);
  cout.tie(0);cin>>n;
  for(int i=0;i<n;i++)
  {
      cin>>x>>num;

      if(x=='|') a|=num,b-=b&num,c-=(c&num);
      if(x=='^') b^=num;
      if(x=='&') a&=num,b&=num,c&=num;
  }

cout<<3<<endl<<"& "<<c<<" | "<<a<<" ^ "<<b;
    return 0;
}