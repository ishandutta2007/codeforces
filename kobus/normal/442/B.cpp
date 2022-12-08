using namespace std;
#include<bits/stdc++.h>
#define SZ(x) ((int)x.size()) 
 
#define maxn 2020
#define MAXN 112345
#define INF INT_MAX
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second
#define double long double


int main(){
 	
 	cout<<setprecision(11)<<fixed;
 	int n;
 	cin>>n;
 	vector<double> v;
 	for(int i=0;i<n;i++){
 		double x;
 		cin>>x;
 		v.pb(x);
 	}
 	sort(v.begin(),v.end());
 	//valor e coisa la
 	pair<double,double> ans=mp(v[v.size()-1],( double)1-v[v.size()-1]);
 	for(int i=n-2;i>=0;i--){
 		if(v[i]*ans.s+(( double)1-v[i])*ans.f<ans.f){
 			break;
 		}
 		ans.f=v[i]*ans.s+(( double)1-v[i])*ans.f;
 		ans.s*=( double)1-v[i];
 	}
 	cout<<ans.f<<endl;
	
	return 0;
}