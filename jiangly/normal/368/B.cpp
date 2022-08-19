#include<bits/stdc++.h>
const int N=1e5+5;
int n,m;
int a[N];
int q_l[N],q_tp[N],ans[N];
bool exist[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&q_l[i]);
		q_tp[i]=i;
	}
	std::sort(q_tp+1,q_tp+m+1,[](int a,int b){return q_l[a]>q_l[b];});
	for(int i=1,cur_l=n+1,cur_ans=0;i<=m;++i){
		int l=q_l[q_tp[i]];
		while(cur_l>l){
			cur_ans+=!exist[a[--cur_l]]++;
		}
		ans[q_tp[i]]=cur_ans;
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}