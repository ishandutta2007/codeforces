#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1000000000
typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long m,b;
	cin>>m>>b;

	long long resp=0;
	long long mark=0;

	while(true){
		long long respar = (mark+1)*mark*(m*(b-mark)+1)/2+(m*(b-mark))*(m*(b-mark)+1)*(mark+1)/2;
		if(respar>resp){
			resp=respar;
		}
		mark++;
		if((b-mark)<0){
			break;
		}
	}

	cout<<resp<<"\n";

	
	return 0;
};