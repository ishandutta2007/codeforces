#include <iostream>
#include <unordered_map>

#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll int,ll int>
#define pdd pair<double,double> 
#define p push 
#define maxn 100001
#define modi 1000000007
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	unordered_map<ll int,int>x ;
	int n;
	ll int temp;
	cin>>n;
	//cout<<n;
	//cout<<"ha"<<"\n";
	int y=n-1;
	ll int z=0;
	for(int i=0;i<n;i++){
		cin>>temp;		
		z+=temp;
		x[z]++;
		y=min(y,n-x[z]);
	}
	cout<<y<<"\n";
}