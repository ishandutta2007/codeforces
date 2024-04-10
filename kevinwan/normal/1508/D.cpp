#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;
mt19937 rng(0);

const int mn=2e3+10;
const double eps=1e-15;
struct dsu{
	int p[mn];
	int f(int x){return (p[x]==x)?x:(p[x]=f(p[x]));}
	void u(int a,int b){p[f(a)]=f(b);}
	dsu(){iota(p,p+mn,0);}
};
int x[mn],y[mn],p[mn];
vi val;
dsu d;
vector<pii>ans;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",x+i,y+i,p+i);
	for(int i=1;i<=n;i++)if(p[i]!=i)val.push_back(i);
	if(!val.size()){printf("0\n");return 0;}
	for(int i=1;i<=n;i++)d.u(i,p[i]);
	sort(val.begin(),val.end(),[](int a,int b){
		return x[a]<x[b];
	});
	int o=val[0];
	sort(val.begin()+1,val.end(),[&o](int a,int b){
		return atan2(ld(x[a]-x[o]),ld(y[a]-y[o]))<atan2(ld(x[b]-x[o]),ld(y[b]-y[o]));
	});
	for(int i=1;i+1<val.size();i++)if(d.f(val[i])!=d.f(val[i+1])){
		ans.push_back({val[i],val[i+1]});
		swap(p[val[i]],p[val[i+1]]);
		d.u(val[i],val[i+1]);
	}
	while(p[o]!=o){
		int pt=p[o];
		swap(p[o],p[pt]);
		ans.push_back({o,pt});
	}
	printf("%d\n",ans.size());
	for(pii p:ans) printf("%d %d\n",p.first,p.second);
}