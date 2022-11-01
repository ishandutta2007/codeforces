#include<bits/stdc++.h>
using namespace std;

#define pii pair < int , int >
#define x first
#define y second
const pii INVALID(1e9 , -1e9);
pii merge(pii p , pii q){return pii(max(p.x , q.x) , min(p.y , q.y));}
bool in(pii p , int q){return p.x <= q && q <= p.y;}
pii pt[4] , ans[4] , px[4] , py[4]; int T , id[4];

bool work(){
	for(int i = 0 ; i < 4 ; ++i) id[i] = i;
	do{
		int x1 , y1 , L = 0;
		if(pt[id[0]].y < pt[id[1]].y){
			int dst = pt[id[1]].y - pt[id[0]].y; pii rx = merge(px[id[0]] , px[id[1]]); rx.x += dst; rx.y += dst;
			for(int i = 2 ; i < 4 ; ++i)
				if(pt[id[i]].y == pt[id[3 - i]].y) rx = merge(rx , px[id[i]]);
				else if(in(py[id[i]] , pt[id[3 - i]].y)) rx = merge(rx , pii(pt[id[i]].x , pt[id[i]].x)); else rx = INVALID;
			if(rx.x <= rx.y){x1 = rx.x - dst; y1 = pt[id[0]].y; L = dst;}
		}
		if(!L && in(px[id[0]] , pt[id[1]].x)){
			x1 = pt[id[1]].x; y1 = pt[id[0]].y; 
			pii ry = py[id[1]] , rx = pt[id[3]].y == y1 ? px[id[3]] : (in(py[id[3]] , y1) ? pii(pt[id[3]].x , pt[id[3]].x) : INVALID);
			ry.x = max(ry.x - y1 , 1); ry.y -= y1; rx.x = max(rx.x - x1 , 1); rx.y -= x1; rx = merge(rx , ry);
			
			if(in(rx , pt[id[2]].x - x1) && in(py[id[2]] , y1 + (pt[id[2]].x - x1))) L = pt[id[2]].x - x1;
			if(in(rx , pt[id[2]].y - y1) && in(px[id[2]] , x1 + (pt[id[2]].y - y1))) L = pt[id[2]].y - y1;
		}
		if(L){ans[id[0]] = pii(x1 , y1); ans[id[1]] = pii(x1 , y1 + L); ans[id[2]] = pii(x1 + L , y1 + L); ans[id[3]] = pii(x1 + L , y1); return 1;}
	}while(next_permutation(id , id + 4));
	return 0;
}

bool check(int mid){
	for(int i = 0 ; i < 4 ; ++i){px[i] = pii(pt[i].x - mid , pt[i].x + mid); py[i] = pii(pt[i].y - mid , pt[i].y + mid);}
	if(work()) return 1;
	for(int i = 0 ; i < 4 ; ++i){swap(pt[i].x , pt[i].y); swap(px[i] , py[i]);}
	bool f = work(); for(int i = 0 ; i < 4 ; ++i) swap(pt[i].x , pt[i].y);
	if(f){for(int i = 0 ; i < 4 ; ++i){swap(ans[i].x , ans[i].y);} return 1;} return 0;
}

int main(){
	for(cin >> T ; T ; --T){
		for(int i = 0 ; i < 4 ; ++i) cin >> pt[i].x >> pt[i].y;
		int L = 0 , R = 1e9; while(L < R){int mid = (L + R) >> 1; check(mid) ? R = mid : L = mid + 1;}
		if(L == 1e9) cout << -1 << endl; else{cout << L << endl; for(int i = 0 ; i < 4 ; ++i) cout << ans[i].x << ' ' << ans[i].y << endl;}
	}
	return 0;
}