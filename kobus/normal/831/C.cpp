#include	<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;

#define MAXN 1000000007
#define INF 1123456789

int notas[2123];
int notpar[2123];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>notas[i];
	}
	for(int i=0;i<k;i++){
		cin>>notpar[i];
	}

	set<int> s;
	set<int> possivel;

	for(int i=1;i<=n;i++){
		for(int j=1;j<k;j++){
			s.insert(notpar[j]);
		}
		int notaparcial=notpar[0];
		for(int j=i;j<n;j++){
			s.erase(notaparcial+notas[j]);
			notaparcial+=notas[j];
		}
		notaparcial=notpar[0];
		for(int j=i-1;j>0;j--){
			s.erase(notaparcial-notas[j]);
			notaparcial-=notas[j];
		}
		if(s.size()==0){
			possivel.insert(notaparcial-notas[0]);
		}
		s.clear();
	}

	cout<<possivel.size()<<"\n";

	return 0;
}