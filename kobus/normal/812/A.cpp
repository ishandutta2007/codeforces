#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a1,a2,a3,p1,b1,b2,b3,p2,c1,c2,c3,p3,d1,d2,d3,p4;
	cin>>a1>>a2>>a3>>p1>>b1>>b2>>b3>>p2>>c1>>c2>>c3>>p3>>d1>>d2>>d3>>p4;
	bool resp=false;
	if(p1==1 && (a1==1 || a2==1 || a3==1 || d3==1 || c2==1 || b1==1)){
		resp=true;
	}
	if(p2==1 && (b1==1 || b2==1 || b3==1 || a3==1 || d2==1 || c1==1)){
		resp=true;
	}
	if(p3==1 && (c1==1 || c2==1 || c3==1 || b3==1 || a2==1 || d1==1)){
		resp=true;
	}
	if(p4==1 && (d1==1 || d2==1 || d3==1 || c3==1 || b2==1 || a1==1)){
		resp=true;
	}
	if (resp==true){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	
	return 0;
}