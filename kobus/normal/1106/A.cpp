#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000007

int vx[5]={-1,-1,0,1,1};
int vy[5]={-1,1,0,-1,1};

int n;

bool isvalid(int x,int y){
	return x>=0&&x<n&&y>=0&&y<n;
}

char m[512][512];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	int resp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int num=0;
			for(int k=0;k<5;k++){
				if(isvalid(i+vx[k],j+vy[k])&&m[i+vx[k]][j+vy[k]]=='X')
					num++;
			}
			resp+=(num==5);
		}
	}
	cout<<resp<<endl;


	return 0;
}