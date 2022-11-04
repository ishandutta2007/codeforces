#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int mv(int&x,int&y,int c){
	cout<<c<<" "<<x+1<<" "<<y+1<<endl;
	if(y==n-2&&x==n-1)return 1;
	if(y==n-1&&x==n-1)return 1;
//	cerr<<"from "<<x<<" "<<y<<endl;
	++x;--y;
	if(x>=n||y<0){
		++y;--x;
		y+=2;
		while(x-1>=0&&y+1<n){--x;++y;}
		while(x<0||y>=n){++x;--y;}
	}
//	cerr<<"to "<<x<<" "<<y<<endl;
	return 0;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	int x1=0,y1=0,x2=0,y2=1;
	int cnt=n*n;
	while(cnt--){
		int c;cin>>c;
		if(c==1){
			if(mv(x2,y2,2)){
				while(cnt--){
					cin>>c;
					if(c==1)mv(x1,y1,3);
					else mv(x1,y1,1);
				}
				return 0;
			}
		}
		else if(mv(x1,y1,1)){
			while(cnt--){
				cin>>c;
				if(c==2)mv(x2,y2,3);
				else mv(x2,y2,2);
			}
			return 0;
		}
	}
}