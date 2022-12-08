#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

pii vi[112345];
int v[112345];
int a[112345];
int n;

int count(){
	int resp=0;
	for(int i=0;i<n;i++)a[i]=v[i];
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
			resp++;
			int mark=i;
			while(a[mark]!=-1){
				int help=mark;
				mark=a[mark];
				a[help]=-1;
			}
		}
	}
	return resp;
}

int findlen(int el){
	int resp=0;
	int mark=el;
	while(resp==0 || mark!=el){
		resp++;
		mark=a[mark];
	}
	return resp;
}

int go(){
	int resp=0;
	for(int i=0;i<n;i++)a[i]=v[i];
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
			cout<<findlen(i)<<" ";
			resp++;
			int mark=i;
			while(a[mark]!=-1){
				cout<<mark+1<<" ";
				int help=mark;
				mark=a[mark];
				a[help]=-1;
			}
			cout<<endl;
		}
	}
	return resp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	for(int i=0;i<n;i++){
		cin>>vi[i].first;
		vi[i].second=i;
	}

	sort(vi,vi+n);

	for(int i=0;i<n;i++){
		v[vi[i].second]=i;
	}

	cout<<count()<<endl;

	go();

	return 0;
}