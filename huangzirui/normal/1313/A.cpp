#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m;
int main(){
	int T;
	cin>>T;
	while(T--){
		k=0;
		int x,y,z;
		cin>>x>>y>>z;
		if(x>0){
			x--;
			++k;
		}
		if(y>0){
			y--;
			++k;
		}
		if(z>0){
			z--;
			++k;
		}
		if((x==1 && y==1 && z>=2)||(x>=2 && y==1 && z==1)||(x==1 && y>=2 && z==1))k+=2;
		else{
			if(x>0 && y>0){
				x--;y--;
				++k;
			}
			if(x>0 && z>0){
				x--;z--;
				++k;
			}
			if(y>0 && z>0){
				y--;z--;
				++k;
			}
			if(x>0 && y>0 && z>0){
				x--;y--;z--;
				++k;
			}
		}
		cout<<k<<endl;
	}
	return 0;
}