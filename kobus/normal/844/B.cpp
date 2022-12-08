
#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int m[51][51];
int r,c;

long long twoto(int a){
	long long resp=1;
	for(int i=0;i<a;i++){
		resp*=2;
	}
	resp--;
	return resp;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r,c;
	cin>>r>>c;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>m[i][j];
		}
	}

	long long res=0;

	for(int i=0;i<r;i++){
		int black=0;
		int white=0;
		for(int j=0;j<c;j++){
			if(m[i][j]==0)white++;
			else black++;
		}
		res+=twoto(white);
		res+=twoto(black);
	}
	for(int i=0;i<c;i++){
		int black=0;
		int white=0;
		for(int j=0;j<r;j++){
			if(m[j][i]==0)white++;
			else black++;
		}
		res+=twoto(white);
		res+=twoto(black);
	}
	res-=r*c;
	cout<<res<<endl;


	return 0;
}