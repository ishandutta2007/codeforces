#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y, wyn=0;
	bool a;
	string s;
	cin>>n>>s;
	if(s[0]=='R'){
		x=1;
		y=0;
		a=false;
	}
	else{
		x=0;
		y=1;
		a=true;
	}
	for(int i=1; i<n; i++){
		if(a){
			if(x==y&&s[i]=='R'){
				wyn++;
				a=false;
			}
		}
		else{
			if(x==y&&s[i]=='U'){
				wyn++;
				a=true;
			}
		}
		if(s[i]=='R'){
			x++;
		}
		else{
			y++;
		}
	}
	cout<<wyn<<'\n';
	return 0;
}