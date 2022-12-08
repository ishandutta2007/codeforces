#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX;
#define MOD 1000000

bool isprime(int a){
	for(int i=2;i*i<=a;i++){
		if(a%i==0)return 0;
	}
	return 1;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int resp=0;
	for(int i=2;i<=n;i++){
		if(isprime(i)){
			int num=i;
			while(num<=n){
				resp++;
				num*=i;
			}
		}
	}

	cout<<resp<<endl;

	for(int i=2;i<=n;i++){
		if(isprime(i)){
			int num=i;
			while(num<=n){
				cout<<num<<" ";
				num*=i;
			}
		}
	}
	cout<<endl;

}