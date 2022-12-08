#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int v[112324];

bool pos(int c,int f, int e){
	c=c-1;f=f-1;e=v[e-1];
	int ori, mae=0;
	for(int i=c;i<=f;i++){
		//cout<<v[i]<<"\n";
		if(v[i]==e){
			ori=i-c;
		}
		if(v[i]<e){
			mae++;
		}
	}
	//cout<<"mae="<<mae<<"\n";
	//cout<<"ori="<<ori<<"\n";
	return mae==ori;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a,b;
	cin>>a>>b;

	for(int i=0;i<a;i++){
		cin>>v[i];
	}

	for(int i=0;i<b;i++){
		int c,f,e;
		cin>>c>>f>>e;
		if(pos(c,f,e)){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}

	return 0;
}