#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin >> t;
	while(t--){
	    long a,b,x,y;
	    cin >> x >> y >> a >> b;
	    long dis = y-x;
	    long t = a+b;
	    if (dis%t!=0) cout << -1 << endl;
	    else cout << dis/t << endl;
	}
}