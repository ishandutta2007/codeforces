#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,t,yes;
ll w,sb,tmp,jb;
vector<int> res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&w);yes=0;
		if(w&1){
			sb=w/2+1;
		}
		else{
			sb=w/2;
		}
		res.clear();tmp=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&jb);
			if(yes){continue;
			}
			if(jb>w){continue;}
			if(jb>=sb){res.clear();res.push_back(i);yes=1;}
			else{
				tmp+=jb;res.push_back(i);
				if(tmp>=sb){yes=1;}
			}
		}
		if(!yes){puts("-1");}
		else{
			printf("%d\n",res.size());
			for(i=0;i<res.size();i++){printf("%d ",res[i]);}
			puts("");
		}
	}
}