#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int h,pd[200],n,B[200],way[200],len,lim,rem;
vector<int>A[200];
void ask(int k){
	printf("? %d\n",k); rem--;
	fflush(stdout);
	int k1; scanf("%d",&k1);
	for (;k1;k1--){
		int k2; scanf("%d",&k2); A[k].push_back(k2);
	}
}
void getlink(){
	int now=1; len=1; way[1]=1;
	//cout<<"asd"<<endl;
	ask(1); if (A[1].size()==1) return;
	now=A[1][0]; //cout<<"asd"<<endl;
	while (1){
		ask(now); way[++len]=now;// cout<<A[now].size()<<endl;
		if (A[now].size()==1) break;
		if (A[now][0]==way[len-1]) now=A[now][1]; else now=A[now][0];
	}
	for (int i=1;i<=len;i++) if (i<len-i+1) swap(way[i],way[len-i+1]);
	now=A[1][1];// cout<<"fa "<<now<<endl;
	while (1){
		ask(now); way[++len]=now;
		if (A[now].size()==1) break;
		if (A[now][0]==way[len-1]) now=A[now][1]; else now=A[now][0];
	}
}
void print(int k){
	printf("! %d\n",k);
	fflush(stdout);
}
int dfs(int k1,int k2){
	if (rem==0) return k1;
	ask(k1);
	if (A[k1].size()==2) return k1;
	if (k2==0) return -1;
	for (int i=0;i<A[k1].size();i++)
		if (A[A[k1][i]].size()==0){
			int k3=dfs(A[k1][i],k2-1);
			if (k3!=-1) return k3;
		}
	return -1;
}
int check(int k1,int k2){
	ask(k1); way[++len]=k1;
	if (A[k1].size()==1) return 1;
	if (k2==0) return 0;
	for (int i=0;i<A[k1].size();i++)
		if (A[A[k1][i]].size()==0) return check(A[k1][i],k2-1);
}
void solve(){
	scanf("%d",&h); n=(1<<h)-1; lim=min(4,h-1); rem=16;
	for (int i=1;i<=n;i++) A[i].clear();
	getlink(); int mid=way[(len+1)>>1],h1=(len>>1)+1;
	if (A[mid].size()==2){
		print(mid); return;
	}
	h1++;
	for (int i=0;i<A[mid].size();i++)
		if (A[A[mid][i]].size()==0){
			mid=A[mid][i]; break;
		}
	while (h1<=lim){
		ask(mid);
		int where=0;
		for (int i=0;i<A[mid].size();i++)
			if (A[A[mid][i]].size()==0) where=A[mid][i];
		len=0;
		int bo=check(where,h1-2);
		if (bo==0){
			for (int i=1;i<=len;i++) A[way[i]].clear();
		} else for (int i=0;i<A[mid].size();i++)
			if (A[A[mid][i]].size()==0&&where!=A[mid][i]) where=A[mid][i];
		mid=where; h1++;
	}
	int ans=dfs(mid,2);
	print(ans);
}
		
		
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}