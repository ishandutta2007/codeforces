#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567
#define INF INT_MAX/2
#define MOD 1000000007
//#define int long long

int m[1123][5];
bool ngud[1123];
int n;

ll dis(int a,int b){
	ll resp=0;
	for(int i=0;i<5;i++){
		resp+=(m[a][i]-m[b][i])*(m[a][i]-m[b][i]);
	}
	return resp;
}
int mark=3;
int next(){
	for(int i=mark;i<n;i++){
		if(ngud[i]==0){
			mark=i+1;
			return i;
		}
	}
	return -1;
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>m[i][j];
		}
	}
	if(n==1){
		cout<<"1\n1\n";
		return 0;
	}
	if(n==2){
		cout<<"2\n1\n2\n";
		return 0;
	}
	int a=0,b=1,c=2;
	while(true){
		if(dis(a,b)<dis(b,c)+dis(a,c)){
			ngud[c]=1;
			c=next();
		}
		else if(dis(b,c)<dis(a,b)+dis(a,c)){
			ngud[a]=1;
			a=next();
		}
		else{
			ngud[b]=1;
			b=next();
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(a==-1 || b==-1 || c==-1)break;
	}
	int resp=0;
	for(int i=0;i<n;i++){
		if(ngud[i]==0){
			for(int j=0;j<n;j++){
				if(j==i)continue;
				for(int k=0;k<n;k++){
					if(k==i || k==j)continue;
					if(dis(j,k)<dis(i,j)+dis(i,k))ngud[i]=1;
				}
				if(ngud[i]==1)break;
			}
		}
		if(ngud[i]==0)resp++;
	}
	cout<<resp<<endl;
	for(int i=0;i<n;i++){
		if(ngud[i]==0){
			cout<<i+1<<endl;
		}
	}








	return 0;
}