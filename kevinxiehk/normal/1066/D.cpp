#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,k,know,kcnt,cnt=0;
	cin>>n>>m>>k;
	know=k;
	kcnt=m;
	int obj[n+5];
	for(int i=1;i<=n;i++){
		cin>>obj[i];
	}
	for(int i=n;i>=1;i--){
		if(obj[i]<=know){
			know-=obj[i];
			cnt++;
		}
		else{
			kcnt--;
			if(kcnt==0){
				cout<<cnt<<endl;
				return 0;
			}
			know=k-obj[i];
			cnt++;
		}
	}
	cout<<n<<endl;
	return 0;
}