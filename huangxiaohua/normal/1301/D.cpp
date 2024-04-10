#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[505][505],f[505][505];
char c[505][505];

struct sb{
	int id,x1,y1,x2,y2,res;
}s[300500];

vector<pair<int,string> >v;

int main(){
	scanf("%d%d%d",&n,&m,&k);

	if((n*(m-1)+m*(n-1))*2<k){
		puts("NO");return 0;
	}
	puts("YES");
	for(i=1;i<n;i++){
		if(!k){
			break;
		}
		if(m==1){
			goto aaa;
		}
		if(3*(m-1)>k){
			j=k/3;
			if(j){
				v.push_back({j,"RDU"});
			}
			k-=j*3;
			if(k==1){
				v.push_back({1,"R"});
			}
			if(k==2){
				v.push_back({1,"RD"});
			}
			k=0;
			break;
		}
		else{
			v.push_back({m-1,"RDU"});
		}
		k-=3*(m-1);
		if(!k){
			break;
		}
		v.push_back({min(k,m-1),"L"});
		k=max(0,k-(m-1));
		aaa:;
		if(!k){
			break;
		}
		v.push_back({1,"D"});
		k--;
		
	}
	if(m==1){
		goto nmsl;
	}
	if(k){
		v.push_back({min(m-1,k),"R"});
		k=max(0,k-(m-1));
	}
	if(k){
		v.push_back({min(m-1,k),"L"});
		k=max(0,k-(m-1));
	}
	nmsl:;
	if(k){
		v.push_back({k,"U"});
	}
	printf("%d\n",v.size());
	for(auto [i,j]:v){
		cout<<i<<' '<<j<<'\n';
	}
}