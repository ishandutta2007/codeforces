#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX;
#define MOD 1000000007

pair<string,string> v[112345];
int ord[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1<s2){
			v[i].f=s1;v[i].s=s2;
		}
		else{
			v[i].s=s1;v[i].f=s2;
		}
	}

	for(int i=0;i<n;i++){
		int y;cin>>y;
		ord[i]=y-1;
	}
	//for(int i=0;i<n;i++)cout<<ord[i]<<endl;
	string ls="";
	for(int i=0;i<n;i++){
		if(v[ord[i]].f>ls)ls=v[ord[i]].f;
		else if(v[ord[i]].s>ls)ls=v[ord[i]].s;
		else{
			cout<<"NO\n";
			return 0;
		}
		//cout<<ls<<endl;
	}
	cout<<"YES\n";
	return 0;
}