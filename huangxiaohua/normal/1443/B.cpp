#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t;
ll a,b,res,l,k,m;
char sb[100500];

int main(){
	scanf("%d",&t);
	while(t--){
		cin>>a>>b>>sb+1;res=0;
		m=1;n=strlen(sb+1);k=114514;l=0;
		for(i=1;i<=n;i++){
			if(sb[i]=='1'){
				if(m){res+=a;m=l=0;continue;}
				res+=min(l*b*k,a);l=0;k=114514;
			}
			else{l++;k=1;}
			//printf("%d %lld\n",i,res);
		}
		printf("%lld\n",res);
	}
}