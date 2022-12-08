#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1000000000
typedef long long ll;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c,v0,v1,a,l;
	cin>>c>>v0>>v1>>a>>l;
	int dias=1;
	int fimant=v0;
	int aant=0;
	int com,fim=0;

	if(v0>=c){
		cout<<1<<"\n";
		return 0;
	}


	while(true){
		com=fimant-l+1;
		fim=com+min(v0+aant+a,v1)-1;
		//cout<<dias<<" "<<com<<" "<<fim<<endl;
		aant+=a;
		fimant=fim;
		dias++;
		if(fim>=c){
			break;
		}
	}

	cout<<dias<<"\n";

	return 0;
}