#include<bits/stdc++.h>
using namespace std;
int ans[3][3],cnt=0,n;
void bsearch(int direction,int a,int s,int e){
	if(s==e){
		ans[cnt][direction]=a;
		ans[cnt][1-direction]=s;
		cnt++;
		return;
	}
	int mid=(s+e)/2,t;
	if(direction==0){
		cout<<"? "<<a<<" "<<s<<" "<<a<<" "<<mid<<endl;
		cout.flush();
	}
	else{
		cout<<"? "<<s<<" "<<a<<" "<<mid<<" "<<a<<endl;
		cout.flush();
	}
	cin>>t;
	if(t%2==1)bsearch(direction,a,s,mid);
	else bsearch(direction,a,mid+1,e);
	return;
}
void guess(int direction,int a){
	int t;
	if(direction==0){
		cout<<"? "<<a<<" "<<1<<" "<<a<<" "<<n<<endl;
		cout.flush();
	}
	else{
		cout<<"? "<<1<<" "<<a<<" "<<n<<" "<<a<<endl;
		cout.flush();
	}
	cin>>t;
	if(t%2==1)bsearch(direction,a,1,n);
	return;
}
int main(){
	cin>>n;
	int r=rand()%n;
	int rplus=r+1;
	int rr=rand()%n;
	int rrplus=rr+1;
	for(int i=rplus;i<=r+n;i++){
		if(cnt==2)break;
		int t=i%n+1;
		guess(0,t);
	}
	for(int i=rrplus;i<=rr+n;i++){
		if(cnt==2)break;
		int t=i%n+1;
		guess(1,t);
	}
	cout<<"! "<<ans[0][0]<<" "<<ans[0][1]<<" "<<ans[1][0]<<" "<<ans[1][1]<<endl;
	return 0;
}