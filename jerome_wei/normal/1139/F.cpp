#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N],s[N],b[N],inc[N],pref[N];
int n,m;
struct Node{
	int x,y,id;
	Node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	bool operator<(const Node b)const{
		return x<b.x;
	}
}nd[N],Inc[N],Dec[N];

int L,R;

typedef long long ll;
const ll P=2e9;
struct SegT{
	int root;
	int t[N*32],cnt,lch[N*32],rch[N*32];
	void add(int &x,ll l,ll r,ll pos,int sum){
		if(!x)x=++cnt;
		t[x]+=sum;
		ll mid=(l+r)>>1;
		if(l==r)return ;
		if(pos<=mid)add(lch[x],l,mid,pos,sum);
		else add(rch[x],mid+1,r,pos,sum);
	}
	int qry(int x,ll l,ll r,ll ql,ll qr){
		if(!x)return 0;
		ll mid=(l+r)>>1;
		int ans=0;
		if(ql<=l&&qr>=r)return t[x];
		if(ql<=mid)ans+=qry(lch[x],l,mid,ql,qr);
		if(qr>mid)ans+=qry(rch[x],mid+1,r,ql,qr);
		return ans;
	}
}T1,T2;
int ret[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)scanf("%d",&inc[i]);
	for(int i=1;i<=m;i++)scanf("%d",&pref[i]);
	for(int i=1;i<=m;i++)
		nd[i]=Node(inc[i],pref[i],i);
	for(int i=1;i<=n;i++){
		Inc[i]=Node(p[i],b[i],i);
		Dec[i]=Node(s[i],b[i],i);
	}
	sort(nd+1,nd+m+1);
	sort(Inc+1,Inc+n+1);
	sort(Dec+1,Dec+n+1);
	int ans=0;
	for(int i=1;i<=m;i++){
		int X=nd[i].x,Y=nd[i].y;
		//cout<<X<<" "<<Y<<endl;
		while(L+1<=n&&Inc[L+1].x<=X){
			++L,++ans;
			ll xx=p[Inc[L].id],yy=b[Inc[L].id];
			//cout<<"in "<<Inc[L].id<<endl;
			T1.add(T1.root,-P,P,xx+yy,1);//l dn
			T2.add(T2.root,-P,P,yy-xx,1);//r up
		}
		while(R+1<=n&&Dec[R+1].x<X){
			++R,--ans;ll xx=p[Dec[R].id],yy=b[Dec[R].id];
			//cout<<"out "<<Dec[R].id<<endl;
			T1.add(T1.root,-P,P,xx+yy,-1);//l dn
			T2.add(T2.root,-P,P,yy-xx,-1);//r up
		}
		int D=0;
		D+=T1.qry(T1.root,-P,P,X+Y+1,P);
		//cout<<"::"<<D<<endl;
		D+=T2.qry(T2.root,-P,P,-P,Y-X-1);
		//cout<<"::"<<D<<endl;
		ret[nd[i].id] = ans-D;
	}
	for(int i=1;i<=m;i++)printf("%d ",ret[i]);
}