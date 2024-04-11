#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007
//#define int long long

char m[512][512];
int d[512][512];

int vx[4]={0,1,0,-1};
int vy[4]={1,0,-1,0};

int l,c;

bool isvalid(pii fi){
	if(fi.f<0||fi.s<0)return 0;
	if(fi.f>=l||fi.s>=c)return 0;
	return m[fi.f][fi.s]=='.';
}


int mark=2;
void dfs(pii u){
	for(int i=0;i<4;i++){
		pii cara=mp(u.f+vx[i],u.s+vy[i]);
		if(isvalid(cara) && d[cara.f][cara.s]==0){
			d[cara.f][cara.s]=mark;
			mark++;
			dfs(cara);
		}
	}
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>l>>c;

	int k;
	cin>>k;

	int x,y;
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			cin>>m[i][j];
			if(m[i][j]=='.'){
				x=i;y=j;
			}
		}
	}
	d[x][y]=1;
	dfs(mp(x,y));

	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			if(d[i][j]>=(mark-k)){
				cout<<"X";
			}
			else cout<<m[i][j];
		}
		cout<<endl;
	}


	return 0;
}