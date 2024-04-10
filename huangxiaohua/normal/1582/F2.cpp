#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[1000500],q[8250][8250],f[8888],it[8888],t1,t2,t3,res[8888],ans;
bitset<8250> vis2[8200];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=8200;i++){
		q[i][++it[i]]=0;
	}
	res[0]=1;ans++;
	for(i=1;i<=n;i++){
		k=a[i];
		while(it[k]){
			t1=q[k][it[k]];
			t2=(t1^k);
			ans+=1-res[t2];res[t2]=1;
			for(j=k;j<=5050;j++){
				if(vis2[t2][j])break;
				vis2[t2][j]=1;
				q[j][++it[j]]=t2;
			}
			it[k]--;
		}
	}
	cout<<ans<<endl;
	for(i=0;i<=8200;i++){
		if(res[i])printf("%d ",i);
	}
}