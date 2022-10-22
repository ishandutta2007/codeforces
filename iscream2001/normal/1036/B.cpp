#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#define LL long long
using namespace std;
const int N=1e5+10;
int q;
LL a,b,c,ans;
int main(){
	cin>>q;
	while(q--){
		cin>>a>>b>>c;
		if(a>c||b>c){
			cout<<-1<<endl;
			continue;
		}
		a=c-(c-a)%2;
		b=c-(c-b)%2;
		cout<<a+b-c<<endl;
	}
}