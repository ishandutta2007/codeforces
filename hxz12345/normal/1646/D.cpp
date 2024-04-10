#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
vector<int> V[1001010];
map<pair<int,int>,int> tag;
bool GG[1001010];
long long final[1001010],ans1,ans2,tot[1001010][3],siz[1001010][3],f[1001010][3],n,i,x,y;
void sc(int x,int fa){
	f[x][1]=1;f[x][0]=0;siz[x][0]=1;siz[x][1]=0;GG[x]=false;
	for (int i=0;i<V[x].size();i++)
	     if (V[x][i]!=fa){
	     	int y=V[x][i];sc(y,x);
	     	f[x][1]+=f[y][0];tot[x][1]+=tot[y][0];siz[x][1]+=siz[y][0];
	     	GG[x]=true;
	     	if (f[y][0]>f[y][1]) f[x][0]+=f[y][0],tot[x][0]+=tot[y][0];
	     	else if (f[y][1]>f[y][0]) 
			     {
				 f[x][0]+=f[y][1];tot[x][0]+=tot[y][1];
				 if (GG[y]) tot[x][0]++;
		      	}
	     	else {
	     		f[x][0]+=f[y][1];
	     		 if (tot[y][0]<tot[y][1]+1) tag[make_pair(x,y)]=0,tot[x][0]+=tot[y][0];
	     	     else tag[make_pair(x,y)]=1,tot[x][0]+=tot[y][1]+1;
			    }
			//if (x==1) cout<<y<<"-----------"<<tot[x][0]<<" "<<tot[y][1]<<" "<<f[y][0]<<" "<<f[y][1]<<endl;
	        }siz[x][1]=max(siz[x][1],(long long)1);
	tot[x][1]+=siz[x][1];tot[x][0]+=siz[x][0];
}
void change(int x,int fa,int sta){
    GG[x]=false;if (sta==0) final[x]=1;
	for (int i=0;i<V[x].size();i++)
	     if (V[x][i]!=fa){
	     	int y=V[x][i];
	     	if (sta==1) {change(y,x,0);final[x]+=final[y];}
	     	else {
	     		if (f[y][0]>f[y][1]) change(y,x,0);
	     		if (f[y][0]<f[y][1]) {change(y,x,1);if (GG[y])final[y]++;}
	     		if (f[y][0]==f[y][1]) {
				 change(y,x,tag[make_pair(x,y)]);
				 if (tag[make_pair(x,y)]==1) final[y]++;
			     }
			 }
			GG[x]=true;
		}
	if (GG[x]==false) final[x]=1;
}
int main()
{
	n=read();
	if (n==2){
		printf("2 2\n1 1\n");
		return 0;
	}
	for (i=1;i<n;i++){x=read();y=read();V[x].push_back(y);V[y].push_back(x);}
    sc(1,0);
    if ((f[1][0]>f[1][1])||((f[1][0]==f[1][1])&&(tot[1][0]<tot[1][1]))) {
    	printf("%lld %lld\n",f[1][0],tot[1][0]);
	change(1,0,0);}
    else {    	printf("%lld %lld\n",f[1][1],tot[1][1]);
	change(1,0,1);}
    for (i=1;i<=n;i++) printf("%lld ",final[i]);
	return 0;
}