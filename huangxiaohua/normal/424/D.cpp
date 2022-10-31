#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[305][305],l[305][305],r[305][305],u[305][305],d[305][305];
int v1,v2,v3,rx1,ry1,rx2,ry2,res=2e9;


void get(int x,int y){
	set<int> s;
	map<int,int> mp;
	int i,j,k,sum=d[n][y]-d[n-1][y]+u[n-1][x]-u[n][x],sum2=0,tmp,tmp2,ans;
	s.insert(-1145141919);
	s.insert(1145141919);
	for(i=n-2;i>=1;i--){
		sum+=(d[i+1][y]-d[i][y]+u[i][x]-u[i+1][x]);
		if(i!=n-2){
			sum2+=(d[i+3][y]-d[i+2][y]+u[i+2][x]-u[i+3][x]);
		}
		tmp=r[i+2][x]-r[i+2][y]-sum2;
		s.insert(tmp);
		mp[tmp]=i+2;
		
		tmp2=l[i][y]-l[i][x]+sum;
		tmp2=t-tmp2;
		auto it=s.lower_bound(tmp2);
		if((*it)==1145141919){goto aaa;}
		ans=abs(tmp2-(*it));
		if(ans<res){
			res=ans;
			ry1=x;rx1=i;
			ry2=y;rx2=mp[*it];
		}
		
		aaa:;
		it--;
		if((*it)==-1145141919){continue;}
		ans=abs(tmp2-(*it));
		if(ans<res){
			res=ans;
			ry1=x;rx1=i;
			ry2=y;rx2=mp[*it];
		}
	}
}

int chk(int x,int y){
	if(x==y){return v2;}
	if(x<y){return v3;}
	return v1;
}

int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&t,&v2,&v3,&v1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=2;j<=m;j++){l[i][j]=l[i][j-1]+chk(a[i][j-1],a[i][j]);}
		for(j=m-1;j>=1;j--){r[i][j]=r[i][j+1]+chk(a[i][j+1],a[i][j]);}
	}
	for(i=1;i<=m;i++){
		for(j=2;j<=n;j++){d[j][i]=d[j-1][i]+chk(a[j-1][i],a[j][i]);}
		for(j=n-1;j>=1;j--){u[j][i]=u[j+1][i]+chk(a[j+1][i],a[j][i]);}
	}
	for(i=1;i<=m;i++){
		for(j=i+2;j<=m;j++){
			get(i,j);
		}
	}
	printf("%d %d %d %d",rx1,ry1,rx2,ry2);
}