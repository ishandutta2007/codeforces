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
	tohi meymoon() kire
		adad asb = bekhun<adad>(), fil = 1;
		bordar<adad> gav;
		kos(kir, asb, 0) kire
			agar (__gcd(asb, kir) == 1) kire
				gav.push_back(kir);
				fil = fil*1ll*kir%asb;
			khar
		khar
		agar (fil != 1)
			gav.erase(find(hame(gav), fil));
		reverse(hame(gav));
		benevis(gav.size(),'\n');
		for(adad i : gav)
			benevis(i, " ");	
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