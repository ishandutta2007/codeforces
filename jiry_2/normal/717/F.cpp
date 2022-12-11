#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct tree{
	int size;
	long long mi0,mi1,r,A;
	void add(long long K){
		if (size&1) r+=K; 
		A+=K; mi0+=K;
	}
}t[810000],ans;
int n,m;
const long long inf=1e18; 
tree operator + (const tree &k1,const tree &k2){
	tree k; k.size=k1.size+k2.size;
	k.A=0; 
	if (k2.size&1) k.r=k2.r-k1.r; else k.r=k2.r+k1.r;
	if (k1.size&1){
		k.mi0=min(k1.mi0,k2.mi1+k1.r);
		k.mi1=min(k1.mi1,k2.mi0-k1.r);
	} else {
		k.mi0=min(k1.mi0,k2.mi0-k1.r);
		k.mi1=min(k1.mi1,k2.mi1+k1.r);
	}
	return k;
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		int k; scanf("%d",&k);
		t[k1]=(tree){1,k-1,inf,k-1,0};
		return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
	t[k1]=t[k1*2]+t[k1*2+1];
}
void pushdown(int k1){
	if (t[k1].A){
		t[k1*2].add(t[k1].A); t[k1*2+1].add(t[k1].A); t[k1].A=0;
	}
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		t[k1].add(k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	t[k1]=t[k1*2]+t[k1*2+1];
}
void find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		ans=ans+t[k1]; 
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	find(k1*2,k2,mid,k4,k5);
	find(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
	scanf("%d",&n);
	buildtree(1,1,n);
	scanf("%d",&m);
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int l,r,k; scanf("%d%d%d",&l,&r,&k);
			add(1,1,n,l+1,r+1,k);
		} else {
			int l,r; scanf("%d%d",&l,&r);
			ans=(tree){0,inf,inf,0,0};
			find(1,1,n,l+1,r+1);
		//	cout<<ans.r<<" "<<ans.mi0<<" "<<ans.mi1<<endl;
			if (ans.r==0&&ans.mi0>=0&&ans.mi1>=0) printf("1\n"); else printf("0\n");
		}
	}
	return 0;
}