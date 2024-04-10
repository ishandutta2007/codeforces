#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[2][1005000],p1[2][1005000],p2[2][1005000],res,cur;

void fuck(int x,int y,int n0,int n1){
	int f1,f2;
	if(x==0&&y==1){
		cur=0;
	}
	else{
		cur=max(cur,a[x][y]);
		cur++;
	}
	if(!n0||!n1)return;
	if(x==0){
		f1=p1[0][n-n0+1]+(n-n0+1);
		f2=p2[1][n-n1+1]-n-n0;
	}
	else{
		f1=p1[1][n-n1+1]+(n-n1+1);
		f2=p2[0][n-n0+1]-n-n1;
	}
	//cout<<"NMSL "<<cur<<' '<<f1<<' '<<f2<<'\n';
	f1=max(f1,f2);
	res=min(res,cur+n0+n1+max(0,f1-cur));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<=1;i++){
			for(j=1;j<=n;j++){
				cin>>a[i][j];
				p1[i][j]=p2[i][j]=a[i][j];
				p1[i][j]-=j;
				p2[i][j]+=j;
			}
		}
		for(i=n-1;i>=1;i--){
			for(j=0;j<=1;j++){
				p1[j][i]=max(p1[j][i],p1[j][i+1]);
				p2[j][i]=max(p2[j][i],p2[j][i+1]);
			}
		}
		//puts("NMSL");
		res=2e9;
		cur=-1;
		for(i=1;i<=n;i++){
			if(i&1){
				fuck(0,i,n-i,n-i+1);
				fuck(1,i,n-i,n-i);
			}
			else{
				fuck(1,i,n-i+1,n-i);
				fuck(0,i,n-i,n-i);
			}
		}
		res=min(res,cur);
		cout<<res<<'\n';
	}
}