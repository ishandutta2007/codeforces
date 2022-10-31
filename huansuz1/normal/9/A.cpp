#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <stack>


using namespace std;

int a,b;

int main(){
	cin>>a>>b;
	a=max(a,b);
	if (a==1) cout<<"1/1";
	else if (a==2) cout<<"5/6";
	else if (a==3) cout<<"2/3";
	else if (a==4) cout<<"1/2";
	else if (a==5) cout<<"1/3";
	else if (a==6) cout<<"1/6";
	return 0;
}