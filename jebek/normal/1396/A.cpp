#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+100;
ll n, a[maxn];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<1<<" "<<n<<endl<<n;
  a[0] += n;
  for(int i=1;i<n;i++)
    {
      ll tmp = ((n-1) - (a[i]%(n-1))) * n;
      cout<<" "<<tmp;
      a[i] += tmp; 
    }
  cout<<endl;
  if(n==1){
    cout<<1<<" "<<1<<endl<<1<<endl;
    a[0]+=1;
  }
  else
    {
      cout<<2<<" "<<n<<endl;
      for(int i=1;i<n;i++)
	{
	  cout<<-a[i]<<" ";
	}
      cout<<endl;
    }
  cout<<1<<" "<<1<<endl<<-a[0]<<endl;
}