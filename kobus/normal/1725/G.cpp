#include "bits/stdc++.h"
#define MAXN 100009
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
int f(int x){
	if(x<=2)return 0;
	if(x==3)return 1; 
	return x-(x+10)/4;
}
int vis[MAXN];
int main(){
    //~ freopen("file.in", "r", stdin);
    int n;
    scanf("%d",&n);
    int st=1,en=INT_MAX;
    while(st<en){
		int mid=(st*1LL+en)>>1;
		if(f(mid)<n)
			st=mid+1;
		else
			en=mid;
	}
	printf("%d\n",st);
	return 0;
}