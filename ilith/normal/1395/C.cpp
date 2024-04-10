#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int b[1010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=0;i<512;i++){
		bool fl=0;
		for(int j=1;j<=n;j++){
			bool suc=0;
			for(int k=1;k<=m;k++){
				if(((a[j]&b[k])|i)==i){
					suc=1;
					break;
				}
			}
			if(!suc){
				fl=1;
				break;
			}
		}
		if(!fl){
			cout<<i;
			return 0;
		}
	}
    return 0;
}