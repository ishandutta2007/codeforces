#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,cnt,num[410000];
struct node{
	int out,in;
	node(int _out=0,int _in=0):out(_out),in(_in){}
	bool operator<(const node &a) const{ return out<a.out;}
} a[210000];
struct Node{
	int v,tot;
	Node(int _v=INF,int _tot=0):v(_v),tot(_tot){}
	Node& operator+=(const Node &a){
		if (v>a.v) v=a.v,tot=a.tot;
		else if (v==a.v) tot=(tot+a.tot)%Mod;
		return *this;
	}
} tree[410000];
void add(int x,Node v){
	for (;x<=cnt;x+=x&-x) tree[x]+=v;
}
Node query(int x){
	Node res;
	for (;x;x-=x&-x) res+=tree[x];
	return res;
}
int main(){
	scanf("%d",&n); int mx=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].out,&a[i].in);
		mx=max(mx,a[i].in);
		num[++cnt]=a[i].in; num[++cnt]=a[i].out;
	}
	sort(a+1,a+n+1);
	sort(num+1,num+cnt+1); cnt=unique(num+1,num+cnt+1)-num-1;
	Node tmp,ans;
	for (int i=1;i<=n;i++){
		int x=lower_bound(num+1,num+cnt+1,a[i].in)-num;
		int y=lower_bound(num+1,num+cnt+1,a[i].out)-num;
		if (a[1].out>a[i].in){
			tmp.v=a[i].in; tmp.tot=1;
		} else{
			tmp=query(x);
			tmp.v+=a[i].in;
		}
		if (mx<a[i].out) ans+=tmp;
		tmp.v-=a[i].out; add(y,tmp);
	}
	printf("%d\n",ans.tot);
	return 0;
}