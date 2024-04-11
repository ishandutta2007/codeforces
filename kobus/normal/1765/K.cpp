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
int main(){
	//freopen("file.in","r",stdin);
	ll sum=0;
	int mn=INF;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int x;
			scanf("%d",&x);
			if(n-i-1==j)
				umin(mn,x);
			sum+=x;
		}
	printf("%lld\n",sum-mn);
	return 0;
}