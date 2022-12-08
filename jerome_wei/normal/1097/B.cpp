#include<bits/stdc++.h>
using namespace std;

int t[400];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t[i];
		t[i]%=360;
	}
	for(int j=0;j<1<<n;j++){
		int ret=0;
		for(int i=1;i<=n;i++){
			if(1&(j>>(i-1))){
				ret+=t[i];
			}else{
				ret-=t[i];
			}
			if(ret>=360)ret-=360;
			if(ret<0)ret+=360;
		}
		if(ret==0){
			cout<< "YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}