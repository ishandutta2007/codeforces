#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long

int dis(int a,int b){
	return a*a+b*b;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b;
	cin>>a>>b;
	
	for(int i=-1;i>-a;i--){
		pii pos1=mp(i,round(sqrt(a*a-i*i)));
		if(dis(pos1.f,pos1.s)!=a*a)continue;
		for(int j=1;j<b;j++){
			//cout<<i<<" "<<j<<endl;
			pii pos2=mp(j,round(sqrt(b*b-j*j)));
			if(dis(pos2.f,pos2.s)!=b*b)continue;
			if(dis(pos2.f-pos1.f,pos2.s-pos1.s)!=a*a+b*b)continue;
			if(pos1.s==pos2.s)continue;
			cout<<"YES"<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<pos1.f<<" "<<pos1.s<<endl;
			cout<<pos2.f<<" "<<pos2.s<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;



	return 0;
}