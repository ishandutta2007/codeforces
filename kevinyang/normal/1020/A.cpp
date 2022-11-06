#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,h,a,b,k;
	cin >> n >> h >> a >> b >> k;
	while(k--){
		int t1,f1,t2,f2;
		cin >> t1 >> f1 >> t2 >> f2;
		if(t2==t1){
			cout << abs(f2-f1) << "\n";
			continue;
		}
		int total = abs(t2-t1);
		if(f1<a &&f2<a){
			total+=abs(f1-a); total+=abs(f2-a);
		}
		else if(f1>b && f2>b){
			total+=abs(f1-b); total+=abs(f2-b);
		}
		else{
			total+=abs(f2-f1);
		}
		cout <<total << "\n";
	}
	return 0;
}