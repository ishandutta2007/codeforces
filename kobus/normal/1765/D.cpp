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
multiset<int>s;
int main(){
	//freopen("file.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		s.insert(x);
		ans+=x;
	}
	int last=m;
	while(s.size()){
		auto it=s.upper_bound(m-last);
		if(it!=s.begin()){
			it--;
			last=*it;
			s.erase(it);
		}
		else{
			last=*s.rbegin();
			s.erase(s.find(last));
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}