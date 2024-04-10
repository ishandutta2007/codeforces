#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+5;

int n;
vector<int> numba[N],numbb[N];
int a[N],b[N],pos[N];
#define lowbit(x) ((x)&(-x))
int t[N];
inline void add(int x,int v){
	for(;x<=n;x+=lowbit(x))t[x]=max(t[x],v);
}
inline int qry(int x){
	int ans=0;for(;x;x-=lowbit(x))ans=max(ans,t[x]);
	return ans;
}



int main(){
	int T;cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++)numba[i].clear(),numbb[i].clear();
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			numba[a[i]].push_back(i);
		}
		for(int i=1;i<=n;++i){
			scanf("%d",&b[i]);
			numbb[b[i]].push_back(i);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(numba[i].size()!=numbb[i].size()){
				puts("No");
				flag=1;break;
			}
			for(size_t j=0;j<numba[i].size();j++){
				pos[numba[i][j]]=numbb[i][j];
			}
		}
		for(int i=1;i<=n;i++)t[i]=0;
		if(flag)continue;
		for(int i=1;i<=n;i++){
			add(a[i],pos[i]);
			if(qry(a[i]) > pos[i]){
				puts("No");flag=1;break;
			}
		}
		if(flag)continue;
		puts("Yes");
	}
}