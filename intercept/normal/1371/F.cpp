#include<bits/stdc++.h>
using namespace std;
const int M=5e5+9;
int n,m,sz;
int val[M<<2][2],ls[M<<2][2],rs[M<<2][2],lv[M<<2][2],rv[M<<2][2];
bool lag[M<<2];
char s[M];
void down(int num){
	swap(val[num][0],val[num][1]);
	swap(rv[num][0],rv[num][1]);
	swap(lv[num][0],lv[num][1]);
	swap(rs[num][0],rs[num][1]);
	swap(ls[num][0],ls[num][1]);
	lag[num]^=1;
}
void pushdown(int num){
	if(lag[num]){
		lag[num]=0;
		down(num<<1);
		down(num<<1|1);
	}
}
int find(int num,int l,int r,int x){
	if(l==r)return ls[num][0]?0:1;
	pushdown(num);
	int mid=l+r>>1,ans;
	if(x<=mid)return find(num<<1,l,mid,x);
	else return find(num<<1|1,mid+1,r,x);
}
void merge(int num,int ch0,int ch1,int ln,int rn,int mi){
	if(ln==0){
		for(int i=0;i<2;++i){
			val[num][i]=val[ch1][i];
			ls[num][i]=ls[ch1][i];
			rs[num][i]=rs[ch1][i];
			lv[num][i]=lv[ch1][i];
			rv[num][i]=rv[ch1][i];
		}
		return;
	}
	if(!num){
		for(int i=0;i<2;++i){
			val[ch0][i]=val[num][i];
			ls[ch0][i]=ls[num][i];
			rs[ch0][i]=rs[num][i];
			lv[ch0][i]=lv[num][i];
			rv[ch0][i]=rv[num][i];
		}
	}
	for(int i=0;i<2;++i){
		val[num][i]=max({val[ch0][i],val[ch1][i],rv[ch0][i^1]+ls[ch1][i^1],lv[ch1][i]+rs[ch0][i]});
		if(lv[ch0][i]==ln){
			if(find(1,1,n,mi)==i){
				lv[num][i]=ln+lv[ch1][i];
			}
			else lv[num][i]=ln+ls[ch1][i^1];
		}
		else lv[num][i]=lv[ch0][i];
		if(rv[ch1][i]==rn){
			if(find(1,1,n,mi+1)==i){
				rv[num][i]=rn+rv[ch0][i];
			}
			else rv[num][i]=rn+rs[ch0][i^1];
		}
		else rv[num][i]=rv[ch1][i];
		ls[num][i]=ls[ch0][i]==ln?ln+ls[ch1][i]:ls[ch0][i];
		rs[num][i]=rs[ch1][i]==rn?rn+rs[ch0][i]:rs[ch1][i];
		
	}
}
void update(int num,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		swap(val[num][0],val[num][1]);
		swap(rv[num][0],rv[num][1]);
		swap(lv[num][0],lv[num][1]);
		swap(rs[num][0],rs[num][1]);
		swap(ls[num][0],ls[num][1]);
		lag[num]^=1;
		return;
	}
	int mid=l+r>>1;
	pushdown(num);
	if(x<=mid)update(num<<1,l,mid,x,y);
	if(y>mid)update(num<<1|1,mid+1,r,x,y);
	merge(num,num<<1,num<<1|1,mid-l+1,r-mid,mid);
}
void query(int num,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		merge(0,(M<<2)-1,num,sz,r-l+1,l-1);
		sz+=r-l+1;
		return;
	}
	pushdown(num);
	int mid=(l+r)>>1;
	if(x<=mid)query(num<<1,l,mid,x,y);
	if(y>mid)query(num<<1|1,mid+1,r,x,y);
} 
void build(int num,int l,int r){
	if(l==r){
		int i=s[l];
		ls[num][i]=rs[num][i]=lv[num][i]=rv[num][i]=val[num][i]=val[num][i^1]=lv[num][i^1]=rv[num][i^1]=1;
		return;
	}
	int mid=l+r>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
	merge(num,num<<1,num<<1|1,mid-l+1,r-mid,mid);
}
void clear(){
	sz=0;
	for(int i=0;i<2;++i)
		ls[0][i]=rs[0][i]=lv[0][i]=rv[0][i]=val[0][i]=0;
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)s[i]=(s[i]=='>')?0:1;
	build(1,1,n);
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r);
		update(1,1,n,l,r);
		clear();
		query(1,1,n,l,r);
		printf("%d\n",val[0][0]);
	}
	return 0;
}
/*
*/