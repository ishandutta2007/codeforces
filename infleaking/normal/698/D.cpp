#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
struct dot{ll x,y;};
dot operator - (dot a,dot b){return (dot){a.x-b.x,a.y-b.y};}
ll cross(dot a,dot b){
	return a.x*b.y-a.y*b.x;
}
ll dot1(dot a,dot b){
	return a.x*b.x+a.y*b.y;
}
ll dis(dot a){
	return a.x*a.x+a.y*a.y;
}
dot ST;
dot p[N],a[N];
bool comp(int a,int b){
	return dis(p[a]-ST)<dis(p[b]-ST);
}
int k,n;
vector<int> c[10][N],h;
void read(dot &x){
	scanf("%lld%lld",&x.x,&x.y);
}
int vis[N],ans,res,tag[N];
void push(vector<int> &a,vector<int> &b){
	for (int i=0;i<b.size();i++)a.push_back(b[i]);
}
void dfs(int x){
	while (h.size()&&tag[h.back()])h.pop_back();
	if (h.empty()){
		res=1;
		return;
	}
//	if (h.size()>k-x+1)return;
	int z=h.back();
	tag[z]=1;
	h.pop_back();
	vector<int> h1=h;
	for (int i=1;i<=k;i++){
		if (vis[i]||c[i][z].size()>k)continue;
		push(h,c[i][z]);
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
		h=h1;
	}
	h.push_back(z);
	tag[z]=0;
}
int main(){
	cin>>k>>n;
	for (int i=1;i<=k;i++)read(a[i]);
	for (int i=1;i<=n;i++)read(p[i]);
	for (int i=1;i<=k;i++)
	for (int x=1;x<=n;x++){
		for (int y=1;y<=n;y++){
			if (cross(p[x]-a[i],p[y]-a[i])==0&&dot1(p[x]-a[i],p[y]-a[i])>0&&dis(p[x]-a[i])>dis(p[y]-a[i])){
				c[i][x].push_back(y);
			}
		}
		ST=a[i];
		sort(c[i][x].begin(),c[i][x].end(),comp);
	}
	for (int i=1;i<=n;i++){
		res=0;
		h.resize(1);
		h[0]=i;
		dfs(1);
		ans+=res;
	}
	cout<<ans<<endl;
}