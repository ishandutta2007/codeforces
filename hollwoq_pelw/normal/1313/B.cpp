#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n,x,y;
		cin >> n >> x >> y;
		if(x>y) swap(x,y);
		printf("%d %d\n",min(n,max(1,x+y-n+1)),max(1,n+1-max(1,(n+1-x)+(n+1-y)-n)));
	}
	return 0;
}