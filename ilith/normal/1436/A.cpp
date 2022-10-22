#include<bits/stdc++.h>
using namespace std;
long long t,n,m,u;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		while(n--){
			cin>>u;
			m-=u;
		}
		if(!m)puts("YES");
		else puts("NO");
	}
	return 0;
}