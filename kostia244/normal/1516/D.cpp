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
#define kos(i, l, r) for(adad i = l; i != (r); i += (l)<(r)?1:-1)
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

struct Meymoon kire
	Meymoon() kire khar
	adad asb, sag, boz[1<<17], maar[1<<17][18];
	tohi meymoon() kire
		memset(boz, 0, sizeof boz);
		memset(maar, 0, sizeof maar);
		bekhun(asb, sag);
		adad goraz;
		adad gav = 0;
		kos(_kir, 1, asb+1) kire
			bekhun(goraz);
			kos(kir, 1, 320) agar(goraz%kir == 0) kire
				agar(goraz/kir < kir) break;
				gav = max({gav, goraz/kir == 1 ? 0 :boz[goraz/kir], kir == 1 ? 0 : boz[kir]});
				boz[goraz/kir] = boz[kir] = _kir;
			khar
			maar[_kir][0] = gav;
			//benevis(_kir, ' ', gav, '\n');
			kos(kir, 1, 18)
				maar[_kir][kir] = maar[maar[_kir][kir-1]][kir-1];
		khar
		adad _kir = sag;
		while(_kir--) kire
			bekhun(asb, sag);
			adad pishi = 0;
			kos(kir, 17, -1) kire
				agar(maar[sag][kir] >= asb)
					sag = maar[sag][kir], pishi += 1<<kir;
			khar
			benevis(pishi+1, '\n');
		khar
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