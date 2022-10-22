#include<iostream>
using namespace std;
long long a[100009],gh[100009],mark[100009],tedad[100009];
int main(){
	long long ans=0,n,x,m1=0;cin>>n;
	for(long long i=1;i<n+1;i++){
		cin>>x;a[i]=x;
		if(tedad[x]>=1){
			tedad[x]++;
			mark[i]=2;
			mark[gh[x]]=0;
			gh[x]=i;
		}
		if(tedad[x]==0){
			m1++;
			tedad[x]++;
			mark[i]=1;
		}
	}
	//for(long long i=1;i<=n;i++){
//		cout<<mark[i]<<" ";
//	}cout<<endl;
	for(long long i=n;i>=1;i--){
		if(mark[i]==1) m1--;
		if(mark[i]!=0 && (mark[i]==2 || (tedad[a[i]]==1))){
			//cout<<i<<"  "<<m1<<endl;
			ans+=m1;
		}
	}
	cout<<ans;
}