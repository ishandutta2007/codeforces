#include<iostream>
using namespace std;
long long a[200009];
int main(){
	long long n,t,x,y,ans;cin>>t;
	for(int pq=0;pq<t;pq++){
		long long gh[200009]={0};
		cin>>n;ans=1e9;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(gh[a[i]]!=0){ans=min(ans,i-gh[a[i]]);}
			gh[a[i]]=i;
		}
		if(ans==1e9)
			cout<<-1<<endl;
		else cout<<ans+1<<endl;
	}
}