#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;


ll a1,a2,a3,b1,b2,b3;

int main() {
	cin>>a1>>b1;
	cin>>a2>>b2;
	cin>>a3>>b3;
	if ((a1==a2 && a2==a3) || (b1==b2 && b2==b3)) {cout<<1; return 0;}
	if ((a1==a2) && ((b1<=b3 && b3>=b2) || (b1>=b3 && b3<=b2))) {cout<<2; return 0;}
	if ((a1==a3) && ((b1<=b2 && b2>=b3) || (b1>=b2 && b2<=b3))) {cout<<2; return 0;}
	if ((a2==a3) && ((b2<=b1 && b1>=b3) || (b2>=b1 && b1<=b3))) {cout<<2; return 0;}
	swap(a1,b1);
	swap(a2,b2);
	swap(a3,b3);
	if ((a1==a2) && ((b1<=b3 && b3>=b2) || (b1>=b3 && b3<=b2))) {cout<<2; return 0;}
	if ((a1==a3) && ((b1<=b2 && b2>=b3) || (b1>=b2 && b2<=b3))) {cout<<2; return 0;}
	if ((a2==a3) && ((b2<=b1 && b1>=b3) || (b2>=b1 && b1<=b3))) {cout<<2; return 0;}
	
	cout<<3;


    return 0;             
}