#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+10;
const int maxv=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	return ch;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,cnt=1;
struct node{
	int sum;
	LL val;
	int li;
	int ls,rs;
}d[N*40];
void add(int l,int r,int id,int v,int tp,int w){
	d[id].sum+=w;
	d[id].val+=(LL)v*(LL)w;
	if(tp) d[id].li+=w;
	if(l==r) return;
	int mid=l+r>>1;
	if(v<=mid) {
		if(!d[id].ls) d[id].ls=++cnt;
		add(l,mid,d[id].ls,v,tp,w);
	}
	else {
		if(!d[id].rs) d[id].rs=++cnt;
		add(mid+1,r,d[id].rs,v,tp,w);
	}
}
LL V;int L;
void ask(int l,int r,int id,int K){
	if(K<=0||d[id].sum==0) return;
	if(l==r) {
		V+=d[id].val;
		L+=d[id].li;
		return;
	}
	int mid=l+r>>1;
	if(d[d[id].rs].sum<=K){
		V+=d[d[id].rs].val;
		L+=d[d[id].rs].li;
		ask(l,mid,d[id].ls,K-d[d[id].rs].sum);
	}
	else{
		ask(mid+1,r,d[id].rs,K);
	}
}
set<int> fir,lit;
int main(){
	set<int>::iterator it;
	scanf("%d",&n);
	int tp,v;
	LL sv=0;
	int sl=0;
	fir.insert(0);
	LL ans;
	int x,y;
	
	for(int i=1;i<=n;++i){
		scanf("%d%d",&tp,&v);
		add(1,maxv,1,abs(v),tp,v/abs(v));
		if(tp) sl+=v/abs(v);
		sv+=(LL)v;
		if(!tp){
			if(v>0) fir.insert(v);
			else fir.erase(abs(v));
		}
		else{
			if(v>0) lit.insert(v);
			else lit.erase(abs(v));
		}
		if(!sl){
			printf("%I64d\n",sv);
			continue;
		}
		V=0;L=0;
		ask(1,maxv,1,sl);
		//cout<<"L "<<V<<" "<<L<<" "<<sv<<" "<<sl<<endl;
		if(L<sl){
			ans=sv+V;
		}
		else{
			it=lit.begin();
			x=*it;
			it=fir.end();
			--it;
			y=*it;
			ans=sv+V;
		//	cout<<"x "<<x<<" "<<y<<endl;
			ans-=(LL)x;
			ans+=(LL)y;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}