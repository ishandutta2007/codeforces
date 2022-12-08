#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,a;
	cin>>k>>a;
	int candies=1;
	while(true){
		k-=candies;
		if(k<0){
			cout<<"Vladik\n";
			return 0;
		}
		candies++;
		a-=candies;
		if(a<0){
			cout<<"Valera\n";
			return 0;
		}
		candies++;
		//roda
	}
	return 0;
}