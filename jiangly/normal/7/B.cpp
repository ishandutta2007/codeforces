//Time Complexity : O(T*M)
//Space Complexity : O(T*M)
#include<bits/stdc++.h>
using namespace std;
const int T=100,M=100,N=100;
int main(){
	int t,m;
	scanf("%d%d",&t,&m);
	vector<int>End(m),Begin(t+1),id(m);
	int Cnt=0;
	for(int i=1;i<=t;++i){
		string opt;
		cin>>opt;
		int n;
		bool f=0;
		switch(opt[0]){
			case 'a':
				scanf("%d",&n);
				for(int j=0,k=0;j<=m-1;++j){
					if(End[j]){
						j=End[j];
						k=j;
						--j;
					}else if(j-k+1==n){
						End[k]=j+1;
						id[k]=++Cnt;
						f=1;
						Begin[Cnt]=k;
						break;
					}
				}
				if(f){
					printf("%d\n",Cnt);
				}else{
					puts("NULL");
				}
				break;
			case 'e':
				scanf("%d",&n);
				if(n>=1&&n<=Cnt&&(~Begin[n])){
					End[Begin[n]]=0;
					id[Begin[n]]=0;
					Begin[n]=-1;
				}else{
					puts("ILLEGAL_ERASE_ARGUMENT");
				}
				break;
			case 'd':
				for(int j=0,k=0;j<=m-1;++j){
					if(End[j]){
						Begin[id[j]]=k;
						id[k]=id[j];
						End[k]=k+End[j]-j;
						if(j!=k){
							End[j]=0;
							id[j]=0;
						}
						k=End[k];
					}
				}
				break;
		}
	}
	return 0;
}