#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
int i,j,k,n,m,t;
int c,d,x,sb,b[20050000];
vector<int> v,p;
ll res,p2[5000]={1};

int main(){
	for(i=2;i<=20000000;i++){
		if(!b[i]){
			for(j=i;j<=20000000;j+=i){
				b[j]++;
			}
		}
	}
	for(i=1;i<=58;i++){
		p2[i]=p2[i-1]*2;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&c,&d,&x);
		res=0;
		v.clear();
		for(i=1;i*i<=x;i++){
			if((i*i)==x){
				v.push_back(x/i);break;
			}
			if((x%i)==0){
				v.push_back(i);
				v.push_back(x/i);
			}
		}
		for(auto j:v){
			sb=j+d;
			if(sb%c){continue;}
			sb/=c;
			res+=p2[b[sb]];
		}
		printf("%lld\n",res);
	}
}