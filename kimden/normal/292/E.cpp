#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
const int MAXN = 100003;

int n,m;
struct triple {
	int x,y,k;
	triple(int a,int b,int c): x(a),y(b),k(c){}
};
vector<triple> queries;

int a[MAXN],b[MAXN];
int tree[4*MAXN];
/*
void build(int tr[4*MAXN], int arr[MAXN],int pos=1,int l=0,int r=n-1){
	if(l==r){
		tr[pos] = arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	build(tr,arr,(pos<<1),l,mid);
	build(tr,arr,(pos<<1)+1,mid+1,r);
}*/

int get(int tr[4*MAXN], int pos, int needPos,int lcur, int rcur){
	if(tr[pos]>=0 && needPos>=lcur && needPos<=rcur){
		return tr[pos];
	}
	if(lcur==rcur && lcur==needPos){
		return tr[pos];
	}
	int mid = lcur + ((rcur-lcur)>>1);
	if(needPos<=mid){
		return get(tr,pos<<1,needPos,lcur,mid);
	}else{
		return get(tr,(pos<<1)+1,needPos,mid+1,rcur);
	}
}

void update(int tr[4*MAXN], int pos, int col, int lcur, int rcur, int l, int r){
	if(rcur<l || lcur>r){
		return;
	}
	if(rcur==r && lcur==l){
		tr[pos] = col;
		return;
	}
	if(tr[pos]>=0){
		tr[pos<<1] = tr[pos];
		tr[(pos<<1)+1] = tr[pos];
	}
	tr[pos] = -1;
	int mid = lcur + ((rcur-lcur)>>1);
	update(tr,pos<<1,col,lcur,mid,max(l,lcur),min(r,mid));
	update(tr,(pos<<1)+1,col,mid+1,rcur,max(l,mid+1),min(r,rcur));
}

int main()
{
	scanf("%d%d",&n,&m);
	int cnt=0;
	int t,x,y,k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<(n<<2);i++){
		tree[i] = -1;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&x,&y,&k);
			queries.push_back(triple(x,y,k));
			update(tree,1,cnt++,0,n-1,y-1,y+k-2);
		}else{
			scanf("%d",&x);
			int u = get(tree,1,x-1,0,n-1);
			int v;
			if(u==-1){
				v = b[x-1];
			}else{
				triple q = queries[u];
				v = a[q.x-q.y+x-1];
			}
			printf("%d\n",v);
		}
	}
}