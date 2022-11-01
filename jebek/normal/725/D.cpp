#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
multiset<ll>s,s1;
ll n,a,tmp,sum,ans,next,tmp1;
pii P[400000];

bool cmp(pii A,pii B)
{
  if(A.X!=B.X) return A.X<B.X;
  return A.Y>B.Y;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>a>>tmp;
  n--;
  for(int i=0;i<n;i++)
    cin>>P[i].X>>P[i].Y;
  sort(P,P+n,cmp);
  while(n>0 && P[n-1].X>a)
    {
      sum++;
      n--;
      s.insert(P[n].Y-P[n].X+1);
    }
  ans=sum;
  while(n)
    {
      next=P[n-1].X;
      while(s.size())
	{
	  tmp=*(s.begin());
	  if(tmp>a-next) break;
	  sum--;
	  a-=tmp;
	  s.erase(s.begin());
	  s1.insert(tmp);
	}
      ans=min(ans,sum);
      //out<<n<<" "<<sum<<" "<<a<<endl;
      sum++;
      n--;
      tmp=P[n].Y-P[n].X+1;
      if(s1.size())
	{
	  tmp1=*(--(s1.end()));
	  //out<<tmp<<" "<<tmp1<<endl;
	  if(tmp<tmp1)
	    {
	      a=a-tmp+tmp1;
	      s.insert(tmp1);
	      s1.erase(--(s1.end()));
	      s1.insert(tmp);
	    }
	  else
	    s.insert(tmp);
	}
      else
	s.insert(tmp);
    }
  next=0;
  while(s.size())
    {
      tmp=*(s.begin());
      if(tmp>a-next) break;
      sum--;
      a-=tmp;
      s.erase(s.begin());
    }
  ans=min(ans,sum);
  cout<<ans+1<<endl;
}