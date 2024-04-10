#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,pos[200500],pos2[200500];
ll tmp,res,a[200500],pre,sum,num,tl,t0,tr;

const int maxn = 1000019,INF = 1e9;
#define size nmsl
int na;
int ch[maxn][2];
int val[maxn],dat[maxn];
int size[maxn],cnt[maxn];
int tot,root;
int Nmsl(int v){
	val[++tot] = v;
	dat[tot] = rand();
	size[tot] = 1;
	cnt[tot] = 1;
	return tot;
	}
void pushup(int id){
	size[id] = size[ch[id][0]] + size[ch[id][1]] + cnt[id];
	}
void build(){
	root = Nmsl(-INF),ch[root][1] = Nmsl(INF);
	pushup(root);
	}
void Rotate(int &id,int d){
	int temp = ch[id][d ^ 1];
	ch[id][d ^ 1] = ch[temp][d];
	ch[temp][d] = id;
	id = temp;
	pushup(ch[id][d]),pushup(id);
	}
void insert(int &id,int v){
	if(!id){
		id = Nmsl(v);
		return ;
		}
	if(v == val[id])cnt[id]++;
	else{
		int d = v < val[id] ? 0 : 1;
		insert(ch[id][d],v);
		if(dat[id] < dat[ch[id][d]])Rotate(id,d ^ 1);
		}
	pushup(id);
	}
int get_rank(int id,int v){
	if(!id)return -2;
	if(v == val[id])return size[ch[id][0]] + 1;
	else if(v < val[id])return get_rank(ch[id][0],v);
	else return size[ch[id][0]] + cnt[id] + get_rank(ch[id][1],v);
	}
int get_val(int id,int rank){
	if(!id)return INF;
	if(rank <= size[ch[id][0]])return get_val(ch[id][0],rank);
		else if(rank <= size[ch[id][0]] + cnt[id])return val[id];
	else return get_val(ch[id][1],rank - size[ch[id][0]] - cnt[id]);
	}

void add(int x){
	for(;x;x-=(-x&x)){a[x]++;}
}

ll get(int x,ll y=0){
	for(;x<=n;x+=(-x&x)){y+=a[x];}
	return y;
}

ll cal(ll x,ll l,ll r){
	//printf("a%d %d %d %d %d\n",sum,pre,x,l,r);
	return l*x-pre+(sum-pre)-r*x-(l*l-l)/2-(r*r+r)/2;
}

int main(){
	build();
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		pos[k]=i;
	}
	for(i=1;i<=n;i++){
		tmp+=get(pos[i]);
		add(pos[i]);
		sum+=pos[i];
		insert(root,pos[i]);
		ll sb=get_rank(root,pos[i])-1;
		
		int mid=(i+1)/2;
		
		if(i==1){pre=pos[1];goto aaa;}
		if(i&1){
			if(sb<=mid){pre+=pos[i];}
			else{
				pre+=get_val(root,mid+1);
			}
		}
		else{
			if(sb<=mid){pre-=get_val(root,mid+2);pre+=pos[i];}
			else{
				
			}
		}
		aaa:;
		res=cal(get_val(root,mid+1),mid,i-mid);
		
		printf("%lld ",res+tmp);
		
	}
}