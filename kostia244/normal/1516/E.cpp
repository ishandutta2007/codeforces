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
#define kos(i, l, r) for(adad i = l; i < (r); i += 1)
#define rkos(i, l, r) for(adad i = l; i > (r); i -= 1)
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

const adad multitest = 0, maar = 1e9 + 7;
struct Meymoon kire
	adad asb, sag, boz[402][402], fil[402][402], gorbe[402], gav[402], gavv[402];
	Meymoon() kire
		memset(boz, 0, sizeof boz);
		memset(fil, 0, sizeof fil);
		memset(gorbe, 0, sizeof gorbe);
		memset(gav, 0, sizeof gav);
		memset(gavv, 0, sizeof gavv);
		gav[0] = 1;
		kos(kir, 1, 402)
			gav[kir] = gav[kir-1]*kir%maar;
		kos(kir, 0, 402)
			gavv[kir] = kosekhar(gav[kir], maar-2);
		kos(kir, 0, 402)
			kos(kjr, 0, kir+1)
				agar (!kjr) fil[kir][kjr] = 1;
				agarna fil[kir][kjr] = (fil[kir-1][kjr]+fil[kir-1][kjr-1])%maar;
	khar
	adad kosekhar(adad pishi, adad goraz) kire
		adad gav = 1;
		while(goraz) kire
			agar (goraz&1)  gav = gav*pishi%maar;
			goraz /= 2, pishi = pishi*pishi%maar;
		khar
		return gav;
	khar
	adad kirekhar(adad pishi, adad goraz) kire
		agar (goraz>pishi || goraz < 0)
			return 0;
		agar(goraz == 0 || goraz == pishi)
			return 1;
		adad gav = 1;
		kos(kir, pishi-goraz+1, pishi+1)
			gav = gav*kir%maar;
		gav = gav*gavv[goraz]%maar;
		return gav;
	khar
	tohi meymoon() kire
		bekhun(asb, sag);
		sag *= 2;
		boz[0][0] = 1;
		kos(kiram, 2, sag+1) kire
			rkos(kir, sag, -1) kire
				kos(kiret, 0, sag+1) kire
					adad bozz = boz[kir][kiret];
					for(adad kjr = 1; kir+kjr*kiram <= sag; kjr++) kire
						bozz = bozz*fil[kir+kjr*kiram][kiram]%maar;
						bozz = bozz*gav[kiram-1]%maar;
						boz[kir+kjr*kiram][kiret+kjr*(kiram-1)] =
						(boz[kir+kjr*kiram][kiret+kjr*(kiram-1)] + bozz*gavv[kjr])%maar;
						//agar (kiram == 2 && kir+kjr*kiram == 2 && kiret+kjr*(kiram-1) == 1) {
						//	benevis(kir, ' ', kiret, ' ', kiram, ' ', kjr, ' ', boz[kir][kiret], '-', bozz ,'\n');
						//} 
					khar
				khar
			khar
		khar
		kos(kir, 0, sag+1) kire
			kos(kiret, 0, sag+1) kire
				//if(boz[kir][kiret]*kirekhar(asb, kir))
				//benevis(kir, ' ', kiret, ' ', boz[kir][kiret], '*', kirekhar(asb,kir), '\n');
				gorbe[kiret] = (gorbe[kiret]+boz[kir][kiret]*kirekhar(asb, kir))%maar;
			khar
		khar
		sag /= 2;
		kos(kir, 2, sag+1)
			gorbe[kir] = (gorbe[kir-2]+gorbe[kir])%maar;
		kos(kir, 1, sag+1)
			benevis(gorbe[kir], ' ');
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