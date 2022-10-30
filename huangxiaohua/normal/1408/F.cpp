#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,a[30000],res=0,tmp[100],tmp2[100],tn=0,tn2=0,r2[30000],tt=0,dp1[50];
int xxx;
vector<int> v[20];

void pr1(int l,int r){
	if(l==r){return;}
	int k=(r-l+1)>>1;
	pr1(l,l+k-1);pr1(l+k,r);
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i+l-1,i+l-1+k);
	}
}

int main(){
	scanf("%d",&n);
	dp1[2]=1;
	for(i=3;i<=15;i++){
		dp1[i]=dp1[i-1]*2+(1<<(i-2));
	}
	if(n<=2){puts("0");return 0;}
	
	for(i=15;i>=0;i--){
		if(n&(1<<i)){
			tn++;tn2++;tmp[tn]=tmp2[tn2]=(1<<i);
			res+=dp1[i+1];
		}
	}
	
	while(tn2>2){
		if(tmp2[tn2]==tmp2[tn2-1]){
			res+=tmp2[tn2];
			tn2--;tmp2[tn2]+=tmp2[tn2+1];
			
			continue;
		}
		else{
			res+=tmp2[tn2];
			tmp2[tn2]+=tmp2[tn2];
			
			continue;
		}
	}
	
	printf("%d\n",res);
	for(i=15;i>=0;i--){
		if(n&(1<<i)){
			pr1(tt+1,tt+(1<<i));tt+=(1<<i);
		}
	}
	tt=0;
	for(i=1;i<=tn;i++){
		for(j=tt+1;j<=tt+tmp[i];j++){
			v[i].push_back(j);
		}
		tt+=tmp[i];
	}
	puts("");
	while(tn>2){

		if(v[tn].size()==v[tn-1].size()){
			tn--;tt=v[tn].size();
			for(j=0;j<tt;j++){
				printf("%d %d\n",v[tn][j],v[tn+1][j]);
				v[tn].push_back(v[tn+1][j]);
			}
			continue;
		}
		else{
			tt=v[tn].size();
			for(j=0;j<tt;j++){
				printf("%d %d\n",v[1][j+xxx],v[tn][j]);
				v[tn].push_back(v[1][j+xxx]);
			}xxx+=tt;
		}
	}
}