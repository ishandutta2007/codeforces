#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1123;
#define mp make_pair
#define f first
#define s second

bool menor(int a,int b){
	if(a%2==0 && b%2==1)return 1;
	return 0;
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int resp=0;
		int f1=0,f0=0,nf=0;
		for(char c:s){
			//cout<<c<<" "<<f0<<" "<<f1<<" "<<nf<<endl;
			if(c=='1'){
				resp+=f1+nf+1;
				f0=f1+nf+1;
				f1=0;
				nf=0;
			}
			if(c=='0'){
				resp+=f0+nf+1;
				f1=f0+nf+1;
				f0=0;
				nf=0;
			}
			if(c=='?'){
				resp+=f0+f1+nf+1;
				swap(f1,f0);
				nf++;
			}
			//cout<<resp<<endl;
		}
		cout<<resp<<endl;
	}

}