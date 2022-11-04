#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);
// rad = deg*pi/180 (rad is measured in M_PI)

ll w,h,alpha;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>w>>h>>alpha;
	if(alpha>=90)alpha=180-alpha;
	if(w<h)swap(w,h);
	if(!alpha){cout<<w*h<<endl;return 0;}
	if(alpha==90){cout<<h*h<<endl;return 0;}
	ld al=alpha*M_PI/180;
	ld b=-(ld)h/(2*cos(al));
	ld a=tan(al);
	ld a2=0,b2=-(ld)h/2;
	ld intersectX=(b2-b)/(a-a2);
	ld twidth=(ld)w/2-intersectX;
	ld theight=twidth*tan(al);
	if(theight<(ld)h){
		ld tprep=sqrtl(twidth*twidth+theight*theight);
		ld first=twidth*theight;
		ld tbase=w-twidth-tprep;
		ld th=tbase/tan(al);
		ld second=tbase*th;
		cout<<setprecision(10)<<fixed<<w*h-first-second<<endl;
	}
	else{
		ld addition=h/tan(al);
		cout<<setprecision(10)<<fixed<<h*(2*intersectX+addition)<<endl;
	}
}