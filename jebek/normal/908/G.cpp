#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MOD=1e9+7;
const int maxn=1000;
ll ans;
int t[20];
ll p[20][maxn],c[maxn][maxn],par[maxn];

ll SUM(ll A, ll B) { return (A+B+MOD)%MOD; }
ll MUL(ll A, ll B) { return (A*B)%MOD; }

void f(int n,int m)
{
  int sum=t[0];
  for(int i=1;i<10;i++)
    {
      ll sum1 = 0;
      for(int x=0;x<=n;x++)
	{
	  sum1=SUM(0,MUL(p[i][x],MUL(p[10-i][n-x],c[n][x])));
	  ans=SUM(ans,MUL(sum1,par[m-x-sum]));
	}
      //ans=SUM(ans,MUL(MUL(MUL(MUL(p[10-i][n-x],p[i][x]),c[n][x]),SUM(one[sum+x+t[i]],-one[sum+x])),i));
      sum+=t[i];
    }
}

int main()
{
  for(int i=1;i<10;i++)
    {
      p[i][0]=1;
      for(int j=1;j<maxn;j++)
	p[i][j]=MUL(p[i][j-1],i);
    }
  ll tmp=1;
  for(int i=1;i<maxn;i++)
    {
      par[i]=SUM(par[i-1],tmp);
      tmp=MUL(tmp,10);
    }
  for(int i=0;i<maxn;i++)
    c[i][i]=c[i][0]=1;
  for(int i=2;i<maxn;i++)
    for(int j=1;j<i;j++)
      c[i][j]=SUM(c[i-1][j],c[i-1][j-1]);
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++)
    {
      int tmp=int(s[i]-'0');
      for(int j=0;j<tmp;j++)
	{
	  t[j]++;
	  f(s.size()-i-1,s.size());
	  t[j]--;
	  //  cerr<<i<<" "<<j<<" "<<ans<<endl;
	}
      t[tmp]++;
    }
  f(0,s.size());
  cout<<ans<<endl;
}