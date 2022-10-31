#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[500500],f[500500],sb,l,r;
int rx,ry,res;

int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	memset(f,0,n*4+50);
    	sb=0;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		f[a[i]]++;
		}
    	sb=-n;
    	l=1;r=0;
    	res=999999;
    	rx=ry=0;
    	for(r=1;r<=n;r++){
    		sb+=f[r]*2;
    		if(sb<m)continue;
    		while((sb-f[l]-f[l])>=m){
    			sb-=f[l]*2;l++;
			}
			//printf("a%d %d %d\n",l,r,sb);
			if((r-l+1)<res){
				res=r-l+1;
				rx=l;ry=r;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]>=rx&&a[i]<=ry)a[i]=1;
			else a[i]=-1;
		}
		
		cout<<rx<<' '<<ry<<'\n';
		l=1;sb=0;
		for(i=1;i<=n;i++){
			sb+=a[i];
			if(m>1&&sb>0){
				cout<<l<<' '<<i<<'\n';
				l=i+1;sb=0;m--;
			}
		}
		cout<<l<<' '<<n<<'\n';
		cout<<'\n';
	}
}