#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int n4,n2,n1;
bool resp=true;
int v[112];

void findseats(int y){
	while(v[y]>=4){
		if(n4>0){
			n4--;
			v[y]-=4;
		}
		else{
			n2--;
			v[y]-=2;
		}
	}
}

void findseats2(int y){
	while(v[y]>0){
		if(v[y]>1 && n2>0){
			n2--;
			v[y]-=2;
		}
		else if(n1>0){
			n1--;
			v[y]-=1;
		}
		else{
			n2--;
			v[y]-=2;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	n4=n;
	n2=2*n;

	for(int i=0;i<k;i++){
		cin>>v[i];
		findseats(i);
	}
	n2+=n4;
	n1+=n4;
	for(int i=0;i<k;i++){
		findseats2(i);
	}

	if(n4>=0 && n2>=0 && n1>=0){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	
	return 0;
}