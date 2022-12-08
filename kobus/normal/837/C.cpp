#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;

#define MAXN 1000000007
#define INF INT_MAX

int m[2][112];

int a,b;

bool fit(int x1,int y1,int x2,int y2){
	int mark=false;
	if((x1+x2<=a && y1<=b && y2<=b)|| (x1+x2<=b && y1<=a && y2<=a)){
		mark=true;
	}
	if((y1+x2<=a && x1<=b && y2<=b)|| (y1+x2<=b && x1<=a && y2<=a)){
		mark=true;
	}
	if((x1+y2<=a && y1<=b && x2<=b)|| (x1+y2<=b && y1<=a && x2<=a)){
		mark=true;
	}
	if((y1+y2<=a && x1<=b && x2<=b)|| (y1+y2<=b && x1<=a && x2<=a)){
		mark=true;
	}
	return mark;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n>>a>>b;

	int maxarea=0;

	for(int i=0;i<n;i++){
		cin>>m[0][i]>>m[1][i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && fit(m[0][i],m[1][i],m[0][j],m[1][j])){
				if(m[0][i]*m[1][i]+m[0][j]*m[1][j]>maxarea){
					maxarea=m[0][i]*m[1][i]+m[0][j]*m[1][j];
				}
			}
		}
	}

	cout<<maxarea<<endl;


	return 0;
}