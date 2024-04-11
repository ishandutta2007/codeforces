#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x1,y1,x2,y2,xp,yp;
	cin>>x1>>y1>>x2>>y2>>xp>>yp;

	int dx=abs(x1-x2),dy=abs(y1-y2);

	if(dx%xp!=0 || dy%yp!=0){
		cout<<"NO\n";
		return 0;
	}

	dx=dx/xp;
	dy=dy/yp;

	if((dx+dy)%2!=0){
		cout<<"NO\n";
		return 0;
	}
	
	cout<<"YES\n";
	return 0;
}