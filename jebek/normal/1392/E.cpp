#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q;
ll a[30][30];

ll find_min(int x,int y)
{
  if(x>=n || y>=n) return 0;
  ll res=a[x][y];
  while(y<n-1)
    {
      y++;
      res+=a[x][y];
    }
  while(x<n-1)
    {
      x++;
      res+=a[x][y];
    }
  return res;
}

ll find_max(int x,int y)
{
  if(x>=n || y>=n) return 0;
  ll res=a[x][y];
  while(x<n-1)
    {
      x++;
      res+=a[x][y];
    }
  while(y<n-1)
    {
      y++;
      res+=a[x][y];
    }
  return res;
}

int main()
{
  cin>>n;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      a[i][j] = 0;
  for(int j=n-2;j>-1;j--)
    for(int i=1;i<n;i++)
      {
	ll tmp1 = find_max(i-1,j+1);
	ll tmp2 = find_min(i,j+1);
	a[i][j] = tmp1-tmp2+1;
      }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	cout<<a[i][j]<<" ";
      cout<<endl;
      cout.flush();
    }

  cin>>q;
  while(q--)
    {
      ll sum;
      cin>>sum;
      int x=0,y=0;
      cout<<x+1<<" "<<y+1<<endl;
      sum -= a[x][y];
      for(int i=0;i<2*n-2;i++)
	{
	  if(x==n-1)
	    y++;
	  else if (y==n-1)
	    x++;
	  else
	    {
	      ll tmp = find_max(x,y+1);
	      if(tmp>=sum)
		y+=1;
	      else
		x+=1;
	    }
	  cout<<x+1<<" "<<y+1<<endl;
	  sum -= a[x][y];
	}
    }
}