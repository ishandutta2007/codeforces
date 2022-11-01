#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
const int maxn=3e5;
int a[maxn],ans[maxn],n;
pii P[maxn];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n);
  for(int i=0;i<n;i++)
    {
      cin>>P[i].X;
      P[i].Y=i;
    }
  sort(P,P+n);
  for(int i=0;i<n;i++)
    ans[P[i].Y]=a[n-i-1];
  for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
}