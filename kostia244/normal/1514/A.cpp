#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
using namespace std;
#define hame(x) begin(x), end(x)
#define kire {
#define khar }
#define bordar vector
#define majmoe set
#define araye array
using adad = int64_t;
using tohi = void;
using reshte = string;

template<class T>
T bekhun() kire
	T gav;
	cin >> gav;
	return gav;
khar
tohi bekhun() kire khar
template<class T, class... Ts>
tohi bekhun(T& gorbe, Ts&... pishi) kire
	gorbe = bekhun<T>();
	bekhun(pishi...);
khar

template<class T>
tohi benevis(T gorbe) kire
	cout << gorbe;
khar
template<class T, class... Ts>
tohi benevis(T gorbe, Ts... pishi) kire
	benevis(gorbe);
	benevis(pishi...);
khar

const adad multitest = 1;

struct Meymoon kire
	Meymoon() kire khar
	adad asb;
	bordar<adad> fil;
	adad sq(adad y) kire
		adad x = sqrt(y);
		return x*x==y||(x-1)*(x-1)==y||(x+1)*(x+1)==y;
	khar
	tohi meymoon() kire
		bekhun<adad>(asb);
		fil.resize(asb);
		adad gav = 0;
		for(auto &i : fil)
			bekhun<adad>(i), gav |= !sq(i);
		benevis(gav ? "YES" : "NO", '\n');
	khar
khar;

main() kire
	adad T;
	if(multitest) T = bekhun<adad>();
	else T = 1;
	while(T--) kire
		Meymoon sag;
		sag.meymoon();
	khar
	
khar


//gav, gorbe, pishi, sag, meymoon, asb, fil, maar, boz, goraz