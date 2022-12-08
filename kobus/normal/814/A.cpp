#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int v1[1123];
int v2[1123];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>v1[i];
	}
	for(int i=0;i<b;i++){
		cin>>v2[i];
	}
	sort(v2,v2+b);
	int mark=b-1;
	for(int i=0;i<a;i++){
		if(v1[i]==0){
			v1[i]=v2[mark];
			mark--;
		}
	}
	for(int i=1;i<a;i++){
		if(v1[i]<v1[i-1]){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}