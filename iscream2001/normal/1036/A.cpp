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
LL a,b;
int main(){
	cin>>a>>b;
	LL c=b/a;
	if(b%a) ++c;
	cout<<c<<endl;
}