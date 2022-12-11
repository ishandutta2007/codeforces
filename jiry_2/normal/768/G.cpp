#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[110000];
int p[110000],len,n,ro;
struct tree{
	int l,r,size;
}t[8000000];
int root[110000],size[110000],dfs[110000],rr[110000],sign,x[110000];
int ans[110000];
vector<int>A,B;
void add(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void dfs1(int k1){
	size[k1]=1; root[k1]=0; dfs[k1]=++sign; x[sign]=k1; //cout<<"sign "<<sign<<" "<<k1<<" "<<x[sign]<<endl;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		dfs1(j); size[k1]+=size[j];
	}
	rr[k1]=sign;
}
int insert(int k1,int k2,int k3,int k4,int k5=1){
	int now=++len; t[now]=t[k1]; t[now].size+=k5;
	if (k2==k3) return now;
	int mid=k2+k3>>1;
	if (mid>=k4) t[now].l=insert(t[k1].l,k2,mid,k4,k5);
	else t[now].r=insert(t[k1].r,mid+1,k3,k4,k5);
	return now;
}
int calc(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return t[k1].size;
	int mid=k2+k3>>1;
	return calc(t[k1].l,k2,mid,k4,k5)+calc(t[k1].r,mid+1,k3,k4,k5);
}
int calc(int k1,int k2){
	int ans=0;
	for (int i=0;i<A.size();i++) ans+=calc(A[i],1,n,k1,k2);
	for (int i=0;i<B.size();i++) ans-=calc(B[i],1,n,k1,k2);
	return ans;
}
void solve(int k1){
	if (p[k1]==0){
		ans[k1]=n-1; return;
	}
	int mi=n+1,ma=0,where=0,se=0;
	root[n+1]=insert(root[n+1],1,n,size[k1],1);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		solve(j); mi=min(mi,size[j]);
		if (size[j]>ma){
			se=ma; ma=size[j]; where=j;
		} else se=max(se,size[j]);
	}
	root[n+1]=insert(root[n+1],1,n,size[k1],-1);
	if (n-size[k1]<mi&&k1!=ro) mi=n-size[k1];
	if (n-size[k1]>ma){
		se=ma; ma=n-size[k1];
		int l=0,r=n+1,an=0;
		while (l<r){
			int mid=l+r>>1;
			if (se>mid){
				l=mid+1; continue;
			}
			int L=ma-mid,R=mid-mi;
			if (L>R){
				l=mid+1; continue;
			}
			A.clear(); B.clear(); A.push_back(root[n]); 
			A.push_back(root[dfs[k1]-1]); B.push_back(root[rr[k1]]);
			B.push_back(root[n+1]);
			if (calc(root[n+1],1,n,L+size[k1],R+size[k1])){
				an=mid; r=mid; continue;
			}
			if (calc(L,R)>0){
				an=mid; r=mid;
			} else l=mid+1;
		}
		ans[k1]=min(ma,an);
	} else {
		se=max(se,n-size[k1]); 
	//	if (k1==1) cout<<"fa "<<mi<<" "<<se<<" "<<ma<<" "<<where<<endl;
		int l=0,r=n+1,an=0;
		while (l<r){
			int mid=l+r>>1;
			if (se>mid){
				l=mid+1; continue;
			}
			int L=ma-mid,R=mid-mi;
		//	if (k1==1) cout<<"mid "<<mid<<" "<<L<<" "<<R<<endl;
			if (L>R){
				l=mid+1; continue;
			}
			A.clear(); B.clear(); A.push_back(root[rr[where]]); B.push_back(root[dfs[where]-1]);
			if (calc(L,R)>0){
				an=mid; r=mid;
			} else l=mid+1;
		}
		ans[k1]=min(ma,an);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1==0) ro=k2; else add(k1,k2);
	}
	if (n==1){
		printf("0\n"); return 0;
	}
	if (n==2){
		printf("1\n1\n"); return 0;
	}
	sign=0; dfs1(ro);
	for (int i=1;i<=n;i++) root[i]=insert(root[i-1],1,n,size[x[i]]);
	solve(ro);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}