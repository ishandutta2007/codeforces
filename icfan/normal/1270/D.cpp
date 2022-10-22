#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 500
int n,k;
map<int,int> mp;
int main(){
	fflush(stdout);
	cin>>n>>k;
	int a,b;
	for(int i=1;i<=k+1;i++){
		cout<<"? ";
		for(int j=1;j<=k+1;j++){
			if(i==j){
				continue;
			}
			cout<<j<<' ';
		}
		cout<<endl;
		cin>>a>>b;
		mp[b]++;
	}
	map<int,int>::iterator it;
	it=mp.end();
	it--;
	cout<<"! "<<(it->second)<<endl;
	return 0;
}