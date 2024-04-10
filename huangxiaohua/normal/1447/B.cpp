#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,res;
vector<int> f,z;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		n=n*m;res=0;
		z.clear();f.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k<0){f.push_back(-k);}
			else{z.push_back(k);}
			res+=abs(k);
		}
		sort(f.begin(),f.end());
		sort(z.begin(),z.end());
		if(f.size()%2==0){printf("%d\n",res);continue;}
		if(z.empty()){z.push_back(1145141919);}
		printf("%d\n",res-f[0]-z[0]+max(z[0]-f[0],f[0]-z[0]));
	}
}