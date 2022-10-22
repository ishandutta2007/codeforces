#include<iostream>
using namespace std;
int t[100099],k,n,th,ts,h[10099],mnh=1e5;string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='H') th++;
		else ts++;
	}
	//cout<<th;
	for(int i=0;i<th;i++){
		h[i]=h[i-1];
		if(s[i]=='T') h[i]++;
	}
	for(int i=n-1;i>=n-th;i--){
		if(s[i]=='T')
			k++;
		//cout<<k<<endl;
		mnh=min(mnh,k+h[th-(n-i)-1]);
	}k=0;
	for(int i=0;i<ts;i++){
		t[i]=t[i-1];
		if(s[i]=='H') t[i]++;
	}
	for(int i=n-1;i>=n-ts;i--){
		if(s[i]=='H')
			k++;
		//cout<<k<<endl;
		mnh=min(mnh,k+t[ts-(n-i)-1]);
	}
	cout<<mnh;
}