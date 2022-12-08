#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int n;
char m[112][112];
int vx[4]={0,1,0,-1};
int vy[4]={1,0,-1,0};

bool isvalid(int y,int x){
	return x>=0&&x<n&&y>=0&&y<n&&m[y][x]=='#';
}

bool clear(int y,int x){
	if(!isvalid(y+1,x))return 0;
	y=y+1;
	m[y][x]='.';
	//cout<<"centro colocado"<<endl;
	for(int i=0;i<4;i++){
		int xp=x+vx[i];
		int yp=y+vy[i];
		if(!isvalid(yp,xp))return 0;
		m[yp][xp]='.';
	}
	return 1;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	cin>>n;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>m[i][j];
  		}
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(m[i][j]=='#'){
  				//cout<<i<<" "<<j<<endl;
  				if(clear(i,j)==false){
  					cout<<"NO"<<endl;
  					return 0;
  				}
  			}
  		}
  	}

  	cout<<"YES"<<endl;
	return 0;
}