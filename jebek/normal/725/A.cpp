#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;

int n;
char c[300000];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>c[i];
    }
  int p=0,q=n-1;
  while(p<n && c[p]=='<') p++;
  while(q>-1 && c[q]=='>') q--;
  cout<<p+n-q-1<<endl;
}