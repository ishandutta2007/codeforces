#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,used[100500],res;
char sb[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>sb+1;
		n=strlen(sb+1);
		memset(used,0,n*4+50);
		res=0;
		for(i=2;i<=n;i++){
			if(sb[i]==sb[i-1]){
				if(!used[i-1]){
					used[i]=1;res++;
				}
			}
			if((i>2)&&(sb[i]==sb[i-2])){
				if(!used[i-2]&&!used[i]){
					used[i]=1;res++;
				}
			}
		}
		printf("%d\n",res);
	}
}