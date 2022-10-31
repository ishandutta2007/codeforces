#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

int a,b,x,y;

int main(){
	cin>>a>>b>>x>>y;
	cout<<max(abs(x-a),abs(y-b));



    return 0;             
}