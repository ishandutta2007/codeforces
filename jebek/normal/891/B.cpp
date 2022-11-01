#include<bits/stdc++.h>
#define Y second
#define X first
using namespace std;

typedef pair<int,int> pii;
int n,ans[100];
pii P[100];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>P[i].X;
      P[i].Y=i;
    }
  sort(P,P+n);
  for(int i=0;i<n;i++)
    ans[P[i].Y]=P[(i+1)%n].X;
  for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
}