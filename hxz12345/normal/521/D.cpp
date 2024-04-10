#include <bits/stdc++.h>
using namespace std;
vector<pair<double,int> > up[101010],mul;
double x,y,a[1000101],chg[100101];
int O[1001010],Answer[1001010],len,j,i,n,Q,m,opt,id[1001010];
bool cmp(long long x,long long y)
{
	return x>y;
}
bool cmp1(pair<double,int> x,pair<double,int> y)
{
	return x.first>y.first;
}
bool cmp2(long long x,long long y)
{
	return O[x]<O[y];
}
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n>>Q>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=Q;i++)
	   {  
	   cin>>opt>>x>>y;O[i]=opt;
	      if (opt==1) 
	          {
	          	if (y>chg[(int)x]) chg[(int)x]=y,id[(int)x]=i;
			  }
	      if (opt==2) up[(int)x].push_back(make_pair(y,i));
	      if ((opt==3)&&(y!=0)) mul.push_back(make_pair(y,i));
	   }
	for (i=1;i<=n;i++) sort(up[i].begin(),up[i].end(),cmp1);
	for (i=1;i<=n;i++)
	    if (chg[i]>a[i]) up[i].push_back(make_pair(chg[i]-a[i],id[i]));
	for (i=1;i<=n;i++)
	    { 
	        x=a[i];
	        for (j=0;j<up[i].size();j++)
	            mul.push_back(make_pair((x+up[i][j].first)/x,up[i][j].second)),x+=up[i][j].first;
	    } 
	sort(mul.begin(),mul.end(),cmp1);len=mul.size();
	printf("%d\n",min(len,m));
	for (i=0;i<min(len,(int)m);i++) Answer[i+1]=mul[i].second;
	len=min(len,m);
	sort(Answer+1,Answer+len+1,cmp2);
	for (i=1;i<=len;i++) printf("%d ",Answer[i]);
	return 0;
}