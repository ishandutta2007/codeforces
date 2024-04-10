#include <bits/stdc++.h>

int se[1000001],a[100001],orig[100001],c[100001],n,m;
//int abs(int x){return (x<0)?-x:x;}
void update(int ind,int num){for(;ind;ind-=ind&-ind)c[ind]=std::min(c[ind],num);}
int query(int ind){
	int ans=0x7f7f7f7f;
	for(;ind<=n;ind+=ind&-ind)ans=std::min(ans,c[ind]);
	return ans;
}
std::vector<std::pair<int,int> >que[100001];
int ans[300001];
void update(int root,int l,int r,int e,int x){
	se[root]=std::max(se[root],x);
	if(l==r)return;
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
}
int getmx(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return std::max(getmx(root<<1,l,(l+r)>>1,el,er),getmx(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),orig[i]=a[i];
	std::sort(orig+1,orig+n+1);
	int lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(orig+1,orig+lim+1,a[i])-orig; 
	memset(c,0x7f7f7f7f,sizeof c);
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		que[r].push_back(std::make_pair(l,i));
	}
	for(int i=1;i<=n;i++){
		for(int l=a[i],r=lim;;){
			int j=getmx(1,1,lim,l,r);
			if(!j)break;
//			printf("%d %d\n",i,j);
			update(j,std::abs(orig[a[i]]-orig[a[j]]));
			r=std::upper_bound(orig+1,orig+lim+1,(orig[a[i]]+orig[a[j]]-1)>>1)-orig-1;
		}
		for(int l=1,r=a[i];;){
			int j=getmx(1,1,lim,l,r);
			if(!j)break;
//			printf("%d %d\n",i,j);
			update(j,std::abs(orig[a[i]]-orig[a[j]]));
			l=std::lower_bound(orig+1,orig+lim+1,(orig[a[i]]+orig[a[j]]+2)>>1)-orig;
		}
		update(1,1,lim,a[i],i);
		for(int j=0;j<que[i].size();j++)
			ans[que[i][j].second]=query(que[i][j].first);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}