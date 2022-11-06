#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
typedef double ld;
const ld eps=1e-9;
typedef pair<ld,int> pi;
const int N=2e5+10;
int w[N],l[N],b[N],n,t,q;
ld z1[N],z2[N],ans;
set<pi>s1,s2;
void del(int x){	
	if (b[x]<l[x])s1.erase(make_pair(z1[x],x));
	if (b[x])s2.erase(make_pair(z2[x],x));
}
void ins(int x){
	ld k=w[x]*(1.0*b[x]/(b[x]+l[x]));
	if (b[x]<l[x]){
		ld k1=w[x]*(1.0*(b[x]+1)/(b[x]+l[x]+1));
		z1[x]=k1-k;
		s1.insert(make_pair(z1[x],x));
	}
	if (b[x]){
		ld k2=w[x]*(1.0*(b[x]-1)/(b[x]+l[x]-1));
		z2[x]=k-k2;
		s2.insert(make_pair(z2[x],x));
	}
}
void add(int x,int v){
	if (b[x]+v<0)return;
	del(x);
	ans-=w[x]*(1.0*b[x]/(b[x]+l[x]));
	b[x]+=v;
	ans+=w[x]*(1.0*b[x]/(b[x]+l[x]));
	ins(x);
}
void go(){
	while (t>0&&s1.size()){
		int x=s1.rbegin()->second;
		add(x,1);t--;
	}
	while (t<0&&s2.size()){
		int x=s2.begin()->second;
		add(x,-1);t++;
	}
	while (s1.size()){
		int x=s1.rbegin()->second,y=s2.begin()->second;
		if (s1.rbegin()->first<s2.begin()->first+eps)break;
		add(x,1);
		add(y,-1);
	}
}
int main(){
	cin>>n>>t>>q;
	for (int i=1;i<=n;i++)scanf("%d",&w[i]);
	for (int i=1;i<=n;i++)scanf("%d",&l[i]);
	for (int x=1;x<=n;x++)z1[x]=w[x]*(1.0/(l[x]+1)),s1.insert(make_pair(z1[x],x));
	go();
	while (q--){
		int ty,x;
		scanf("%d%d",&ty,&x);ty=(ty%2)*2-1;
		del(x);
		ans-=w[x]*(1.0*b[x]/(b[x]+l[x]));
		l[x]+=ty;
		if (ty==-1&&b[x]>l[x])b[x]--,t++;
		ans+=w[x]*(1.0*b[x]/(b[x]+l[x]));
		ins(x);
		go();
		printf("%.12lf\n",ans);
	}
}