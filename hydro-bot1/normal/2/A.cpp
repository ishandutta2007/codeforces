// Hydro submission #630761ef857e326068ab51d9@1661428208429
#include<bits/stdc++.h>
using namespace std;
map<string,int> Q,P;
int n,f[1005],maxn=-1;
string name[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name[i]>>f[i];
		Q[name[i]]+=f[i];
	}
	for(int i=1;i<=n;i++)
		maxn=max(maxn,Q[name[i]]);
	for(int i=1;i<=n;i++){
		P[name[i]]+=f[i];
		if(Q[name[i]]==maxn&&P[name[i]]>=maxn){
			cout<<name[i];
			break;
		}
	}
	return 0;
}