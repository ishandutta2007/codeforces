#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b){
	if(!b){return a;}
	return gcd(b,a%b);
}

int i,j,k,n,t,x,y,a,b,c,d;

unordered_map< int,unordered_map<int,int> >mp;

ll res;

int main(){
	scanf("%d",&t);
	while(t--){
		mp.clear();
		res=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			x=c-a;y=d-b;
			if(!x){
				if(y>0){y=1;}
				else{y=-1;}
				goto aaa;
			}
			if(!y){
				if(x>0){x=1;}
				else{x=-1;}
				goto aaa;
			}
			a=gcd(x,y);
			a=abs(a);
			x/=a;y/=a;
			aaa:
			//printf("%d %d\n",x,y);
			res+=mp[-x][-y];
			mp[x][y]++;
		}
		printf("%lld\n",res);
	}
}