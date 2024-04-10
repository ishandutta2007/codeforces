#include<iostream>
#include<algorithm>
#include<set>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
int n,q,k1,k2,ans;
set<pii>s[2];

int main()
{
  cin>>n>>q;
  for(int i=0;i<q;i++)
    {
      int x,y,a;
      char c;
      cin>>x>>y>>c;
      if(c=='L')
	a=0,swap(x,y);
      else
	a=1;
      set<pii>::iterator it=s[a].lower_bound(pii(x,0));
      if(it!=s[a].end())
	{
	  k1=it->X,k2=it->Y;
	  if(k1==x)
	    ans=y;
	  else
	    ans=k2;
	}
      else
	ans=0;
      //  cout<<x<<" "<<y<<endl;
      set<pii>::iterator it1=s[1-a].lower_bound(pii(y+1,0));
      if(s[1-a].size()!=0 && it1!=s[1-a].begin())
	{
	  it1--;
	  k1=it1->X,k2=it1->Y;
	  if(k2<x)
	    ans=max(ans,k1);
	}
      if(ans!=y)
	s[a].insert(pii(x,ans));
      cout<<y-ans<<endl;
    }
}