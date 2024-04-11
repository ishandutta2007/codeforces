#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int main(){
	int n, b, d;
	cin >> n >> b >> d;
	int ret = 0, dap = 0;
	while(n--){
		int x;
		scanf("%d",&x);
		if(x <= b){
			ret+=x;
			if(ret > d){
				ret = 0;
				dap++;
			}
		}
	}
	cout<<dap;
}