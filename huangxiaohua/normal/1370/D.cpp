#include<bits/stdc++.h>
using namespace std;

int i,j,n,t,k,a[200500],fa[200500],len[200500],res,r1,r2,m;
vector<pair<int,int> >v;
int find(int x){return (x==fa[x])?x:fa[x]=find(fa[x]);}

int main(){
	r1=r2=1145141919;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.push_back({a[i],i});
	}
	sort(v.begin(),v.end());
	if(m&1){
		for(i=1;i<=n;i++){
			fa[i]=i;len[i]=0;
		}
		res=0;
		for(auto [j,i]:v){
			if(i==1||i==n){continue;}
			find(i);find(i-1);find(i+1);
			k=len[fa[i-1]];
			if(k){
				len[i]+=k;fa[fa[i-1]]=i;res-=(k+1)/2;
			}
			k=len[fa[i+1]];
			if(k){
				len[i]+=k;fa[fa[i+1]]=i;res-=(k+1)/2;
			}
			len[i]++;
			res+=(len[i]+1)/2;
			if(res>=m/2){r1=j;break;}
		}
		
		for(i=1;i<=n;i++){
			fa[i]=i;len[i]=0;
		}
		res=0;
		for(auto [j,i]:v){
			find(i);find(i-1);find(i+1);
			k=len[fa[i-1]];
			if(k){
				len[i]+=k;fa[fa[i-1]]=i;res-=(k+1)/2;
			}
			k=len[fa[i+1]];
			if(k){
				len[i]+=k;fa[fa[i+1]]=i;res-=(k+1)/2;
			}
			len[i]++;
			res+=(len[i]+1)/2;
			if(res>m/2){r2=j;break;}
		}
	}
	else{
		for(i=1;i<=n;i++){
			fa[i]=i;len[i]=0;
		}
		res=0;
		for(auto [j,i]:v){
			if(i==1){continue;}
			find(i);find(i-1);find(i+1);
			k=len[fa[i-1]];
			if(k){
				len[i]+=k;fa[fa[i-1]]=i;res-=(k+1)/2;
			}
			k=len[fa[i+1]];
			if(k){
				len[i]+=k;fa[fa[i+1]]=i;res-=(k+1)/2;
			}
			len[i]++;
			res+=(len[i]+1)/2;
			if(res>=m/2){r1=j;break;}
		}
		
		for(i=1;i<=n;i++){
			fa[i]=i;len[i]=0;
		}
		res=0;
		for(auto [j,i]:v){

			if(i==n){continue;}
			find(i);find(i-1);find(i+1);
			k=len[fa[i-1]];
			if(k){
				len[i]+=k;fa[fa[i-1]]=i;res-=(k+1)/2;
			}
			k=len[fa[i+1]];
			if(k){
				len[i]+=k;fa[fa[i+1]]=i;res-=(k+1)/2;
			}
			len[i]++;
			res+=(len[i]+1)/2;
			if(res>=m/2){r2=j;break;}
		}
	}
	printf("%d",min(r1,r2));
}