#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,xx,yy,x,y;

vector<pair<int,int> >v1,v2;
int main(){
	cin>>x>>y;
	for(i=-2000;i<=2000;i++){
		for(j=-2000;j<=2000;j++){
			if(!i||!j)continue;
			if((i*i+j*j)==(x*x))v1.push_back({i,j});
			if((i*i+j*j)==(y*y))v2.push_back({i,j});
		}
	}
	for(auto [i,j]:v1){
		for(auto [k,l]:v2){
			xx=(i-k);yy=(j-l);
			if(i==k||j==l)continue;
			if((x*x+y*y)==(xx*xx+yy*yy)){
				printf("YES\n%d %d\n%d %d\n0 0",i,j,k,l);
				return 0;
			}
		}
	}
	puts("NO");
}