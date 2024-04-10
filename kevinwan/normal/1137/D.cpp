#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e3+10;

int main(){
	while(1){
		printf("next 0 1\n");
		fflush(stdout);
		int t;
		scanf("%d",&t);
		string s;
		for(int i=0;i<t;i++)cin>>s;
		printf("next 1\n");
		fflush(stdout);
		scanf("%d",&t);
		for(int i=0;i<t;i++)cin>>s;
		if(t==2)break;
	}
	while(1){
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
		int t;
		scanf("%d",&t);
		string s;
		for(int i=0;i<t;i++)cin>>s;
		if(t==1){
			printf("done\n");
			fflush(stdout);
			return 0;
		}
	}
}