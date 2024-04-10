#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
void work(){
	int n;
	cin>>n;
	bool flag=0,bol=0;
	for(int i=1,la=0;i<=n;++i){
		int x;
		cin>>x;
		if(la>x)bol=1;
		if(la<x&&bol){
			flag=1;
		}
		la=x;
	}
	puts(flag?"NO":"YES");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}