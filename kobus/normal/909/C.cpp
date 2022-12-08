#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int comax=2;
int coms[11234];
int pre[11234];

void dtt(int f){
	for(int i=0;i<comax;i++){
		pre[0]+=coms[i];
		pre[0]=pre[0]%MOD;
		pre[i+f+1]-=coms[i];
		pre[i+f+1]=(pre[i+f+1]+MOD)%MOD;
	}
	comax+=f;
	coms[0]=pre[0]%MOD;
	for(int i=1;i<comax;i++){
		coms[i]=(coms[i-1]+pre[i]+MOD)%MOD;
		pre[i]=0;
	}
	pre[0]=0;
	return;
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	coms[0]=1;

	int fors=0;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		if(c=='f'){
			fors++;
		}
		else if(i!=n-1){
			//cout<<"fors "<<fors<<endl;
			dtt(fors);
			fors=0;
			/*cout<<"histo "<<i<<endl;
			for(int j=0;j<=comax;j++){
				cout<<j<<" "<<coms[j]<<endl;
			}*/
		}
	}

	int resp=0;
	for(int i=0;i<=comax;i++){
		resp+=coms[i];
		resp=resp%MOD;
		//cout<<i<<" "<<coms[i]<<endl;
	}

	cout<<resp<<endl;


	return 0;
}