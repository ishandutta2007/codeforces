#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=1e9;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
int n;
vector<int> V[200005];
int du[200005],f[200005];
int q[200005];
void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) V[i].clear();
	for(int i=1;i<=n;++i){
		scanf("%d",&du[i]);
		for(int j=1;j<=du[i];++j){
			scanf("%d",&u);
			V[u].push_back(i);
		}
	}
	int l=1,r=0;
	for(int i=1;i<=n;++i){
		f[i]=0;
		if(!du[i]){
			q[++r]=i;
			f[i]=1;
		}
	}
	//cout<<"? "<<r<<" "<<q[1]<<endl;
	while(l<=r){
		u=q[l++];
		for(int i=0;i<V[u].size();++i){
			if(V[u][i]<u){
			//	cout<<V[u][i]<<" "<<u<<endl; 
				f[V[u][i]]=max(f[V[u][i]],f[u]+1);
			}
			else{
				f[V[u][i]]=max(f[V[u][i]],f[u]);
			}
			du[V[u][i]]--;
			if(du[V[u][i]]==0){
				q[++r]=V[u][i];
			}
		}
	}
	if(r!=n) puts("-1");
	else {
		v=0;
		for(int i=1;i<=n;++i){
			v=max(v,f[i]);
		}
		printf("%d\n",v);
	}
	return;
} 

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
*/