#include <bits/stdc++.h>

std::priority_queue<std::pair<long long,int> >heap;
int n,a[500001],x,cnt[500001];
long long dis1[300001],dis2[300001];
int mn[300001],m,p,q;
char map[300001];
int Q[300001][2],h,t;
int hash(int i,int j){
	return i*m+j;
}
void push(int i,int j){
	++t;
	Q[t][0]=i;
	Q[t][1]=j;
}
bool check(int i,int j,char ch){
	if(i<0||j<0||i>=n||j>=m)return 0;
	if(map[hash(i,j)]!=ch)return 0;
	return 1;
}
void upd(int i,int j,long long d1,int ind,long long d2){
	bool bb=1;
	if(dis1[hash(i,j)]>d1){
		dis2[hash(i,j)]=dis1[hash(i,j)];
		dis1[hash(i,j)]=d1;
		mn[hash(i,j)]=ind;
		heap.push(std::make_pair(-dis1[hash(i,j)],hash(i,j)));
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&p,&q);
	for(int i=0;i<n*m;++i){
		char ch=getchar();
		while(ch!='.'&&ch!='#'&&ch!='U'&&ch!='D'&&ch!='L'&&ch!='R')ch=getchar();
		map[i]=ch;
	}
	for(int i=0;i<n*m;++i)dis1[i]=dis2[i]=1000000000000000000ll;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(map[hash(i,j)]=='.'){
				dis1[hash(i,j)]=0;
				mn[hash(i,j)]=hash(i,j);
				heap.push(std::make_pair(0,hash(i,j)));
			}
	while(!heap.empty()){
		int ind=heap.top().second;
        heap.pop();
		int y=ind%m,x=(ind-y)/m;
		// printf("%d %d %lld %lld\n",x,y,dis1[ind],dis2[ind]);
		if(check(x-1,y,'L'))upd(x-1,y+1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x-1,y,'R'))upd(x-1,y-1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x-1,y,'D'))upd(x-2,y,dis1[ind]+q,mn[ind],dis2[ind]+q);
		if(check(x+1,y,'L'))upd(x+1,y+1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x+1,y,'R'))upd(x+1,y-1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x+1,y,'U'))upd(x+2,y,dis1[ind]+q,mn[ind],dis2[ind]+q);

		if(check(x,y-1,'D'))upd(x-1,y-1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x,y-1,'U'))upd(x+1,y-1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x,y-1,'R'))upd(x,y-2,dis1[ind]+q,mn[ind],dis2[ind]+q);
		if(check(x,y+1,'D'))upd(x-1,y+1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x,y+1,'U'))upd(x+1,y+1,dis1[ind]+p,mn[ind],dis2[ind]+p);
		if(check(x,y+1,'L'))upd(x,y+2,dis1[ind]+q,mn[ind],dis2[ind]+q);
	}
	long long ans=1000000000000000000ll;
	for(int i=0;i<n;++i)
		for(int j=0;j+1<m;++j)
			ans=std::min(ans,dis1[hash(i,j)]+dis1[hash(i,j+1)]);
	for(int i=0;i+1<n;++i)
		for(int j=0;j<m;++j)
			ans=std::min(ans,dis1[hash(i,j)]+dis1[hash(i+1,j)]);
	if(ans==1000000000000000000ll)puts("-1");
	else printf("%lld\n",ans);
}