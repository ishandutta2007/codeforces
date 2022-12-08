#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 3123
#define INF LLONG_MAX
#define MOD 1000000007

int tento(int a){
	int resp=1;
	for(int i=0;i<a;i++)resp*=10;
	return resp;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a,b;
	cin>>a>>b;

	int bn=0;

	for(int i=0;i<b.size();i++){
		bn*=10;
		bn+=(b[i]-'0');
	}

	//cout<<bn<<endl;

	int an=0;
	multiset<int> sobra;

	for(int i=0;i<a.size();i++){
		int maxd=0;
		int maxdi=0;
		for(int j=i;j<a.size();j++){
			int num=0;
			for(int k=i;k<a.size();k++){
				if(k==j)num=a[k]-'0';
				else sobra.insert(a[k]-'0');
			}
			for(int k=i+1;k<a.size();k++){
				//cout<<"entra"<<endl;
				num*=10;
				num+=*sobra.begin();
				sobra.erase(sobra.begin());
			}
			if(an+num<=bn){
				if(a[j]-'0'>=maxd){
					maxd=a[j]-'0';
					maxdi=j;
				}
			}
		}
		//cout<<maxd<<endl;
		an+=(maxd*tento(a.size()-i-1));

		//cout<<an<<endl;

		swap(a[i],a[maxdi]);
		//cout<<i<<" "<<maxd<<" "<<tento(a.size()-i-1)<<endl;
	}

	cout<<an<<endl;

  	return 0;

}