#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200010];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int now=1,tea=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++,now++){
			if(a[i]<=now){
				now=0;
				tea++;
			}
		}
		cout<<tea<<'\n';
	}
	return 0;
}