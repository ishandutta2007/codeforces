#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123456
#define INF INT_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int>
#define double long double 

int v[MAXN];
int melhordiv[MAXN];

vector<int> divisores(int x){
	int num=2;
	vector<int> resp;
	while(num*num<=x){
		if(x%num==0){resp.pb(num);if(num*num!=x)resp.pb(x/num);}
		num++;
	}
	resp.pb(x);
	return resp;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(11)<<fixed;

	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>v[i];
	int resp=0;
	for(int i=n-1;i>=0;i--){
		int melhor=0;
		vector<int> div=divisores(v[i]);

		//cout<<"divisores de "<<v[i]<<endl;
		//for(int x:div)cout<<x<<" ";
		//cout<<endl;

		for(int x:div)melhor=max(melhor,melhordiv[x]);
		melhor++;
		for(int x:div)melhordiv[x]=max(melhordiv[x],melhor);

		//for(int i=0;i<=10;i++){
			//cout<<i<<" "<<melhordiv[i]<<"   ";
		//}
		//cout<<endl;

		resp=max(resp,melhor);
	}
	cout<<resp<<endl;




	return 0;
}