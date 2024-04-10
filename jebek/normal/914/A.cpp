#include<bits/stdc++.h>
using namespace std;

const int off=1e6+10;
int n;
bool mark[3*off];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      mark[tmp+off]=true;
    }
  for(int i=0;i*i<=off;i++)
    mark[i*i+off]=false;
  for(int i=off;i>=-off;i--)
    if(mark[i+off])
      {
	cout<<i<<endl;
	return 0;
      }
}