#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int arr[MAXN];
ll lcm(int x,int y){
	return x/__gcd(x,y)*y;
}
int main(){
	//freopen("file.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
	    vector<int>v;
		int n;
		scanf("%d",&n);
		for(int i=2;i*i<=n;i++)
			if(n%i==0){
				v.pb(i);
				v.pb(n/i);
			}
		int A=1,B=n-1;
		ll mn=lcm(A,B);
		for(auto a:v){
			int b=n-a;
			if(umin(mn,lcm(a,b)))
				A=a,B=b;
		}
		printf("%d %d\n",A,B);
	}
	return 0;
}