#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,l2[200500],m,cl,cr,t;

ll mx[200505][21],mn[200505][21],a[200500];
ll chkmx(int l,int r){int k=l2[r-l+1];return max(mx[l][k],mx[r-(1<<k)+1][k]);}
ll chkmn(int l,int r){int k=l2[r-l+1];return min(mn[l][k],mn[r-(1<<k)+1][k]);}

int main(){
	ios::sync_with_stdio(0);
	l2[0]=-1;
	for(i=1;i<=200005;i++){
		l2[i]=l2[i>>1]+1;
	}
	
	cin>>t;
	while(t--){
		cin>>n>>cr;
		cl=cr-1;
		
		for(i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=a[i-1];
			mx[i][0]=mn[i][0]=a[i];
		}
		for(j=1;j<=18;j++){
			for(i=0;i+(1<<j)-1<=n;i++){
				mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
				mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
			}
		}
		while(1){
			int l,r,md,ans,l1=cl,r1=cr;
			
			l=0; r=cl; ans=cl;
			while(l<=r){
				md=(l+r)/2;
				if(chkmx(md,cl)<=a[cr]){
					ans=min(ans,md);r=md-1;
				}
				else l=md+1;
			}
			
			//cout<<ans<<endl;
			if(ans==0){
				cout<<"YES\n";goto aaa;
			}
			for(i=cl-1;i>=ans;i--){
				if(a[i]==chkmn(ans,cl)){
					cl=i;break;
				}
			}
			
			l=cr; r=n; ans=cr;
			while(l<=r){
				md=(l+r)/2;
				if(chkmn(cr,md)>=a[cl]){
					ans=max(ans,md);l=md+1;
				}
				else r=md-1;
			}
			if(ans==n){
				cout<<"YES\n";goto aaa;
			}
			for(i=cr+1;i<=ans;i++){
				if(a[i]==chkmx(cr,ans)){
					cr=i;break;
				}
			}
			
			//printf("NMSL%d %d %d %d\n",cl,cr,a[cl],a[cr]);
			if(l1==cl&&r1==cr)break;
		}
		cout<<"NO\n";
		aaa:;
	}
}