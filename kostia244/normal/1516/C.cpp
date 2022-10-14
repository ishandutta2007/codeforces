//koskesh hack nakon
//harki hack kone kunie
//kune laghet agar hack koni

//coded by KIRtia244
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
using namespace std;
#define hame(x) begin(x), end(x)
#define kire {
#define khar }
#define agar if
#define agarna else
#define bordar vector
#define majmoe set
#define araye array
#define kos(i, l, r) for(adad i = l; i != r; i += (l)<(r)?1:-1)
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

const adad multitest = 0;
const adad maar = 1e9 + 7;

struct Meymoon kire
	Meymoon() kire khar
	adad asb;
	bordar<adad> fil;
	adad pishi(adad gorbe) kire
		bitset<2020*2020> sag;
		sag[0] = 1;
		for(auto kir : fil)
			sag |= sag<<kir;
		return gorbe%2 || !sag[gorbe/2];
	khar
	tohi meymoon() kire
		bekhun(asb);
		fil.resize(asb);
		adad goraz = 1ll<<60, gorbe = 0;
		for(auto &kir : fil)
			bekhun(kir), goraz = __gcd(goraz, kir), gorbe += kir;
		araye<int, 2> sag = {1<<30, 1<<30};
		for(auto &kir : fil) kir /= goraz;
		agar (pishi(gorbe/goraz)) sag = {0, 0};
		agarna kire 
			adad kir = 0;
			while(fil[kir]%2==0) kir++;
			sag = {1, ++kir};
		khar
		benevis(sag[0]);
		agar (sag[0])
			benevis('\n', sag[1]);
	khar
khar;

main() kire
	adad T;
	agar (multitest) T = bekhun<adad>();
	agarna T = 1;
	while(T--) kire
		Meymoon sag;
		sag.meymoon();
	khar
	
khar

//gav, gorbe, pishi, sag, meymoon, asb, fil, maar, boz, goraz