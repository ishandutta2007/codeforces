//== 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define uint unsigned int
#define ll int
#define ull uint
#define pb push_back
using namespace std;
/***********************************************/
uint n,qq;
/***********************************************/
class Dot{
public:
	ll pos;
	ll time;	//" zone " 
	int type;
};
bool dot_cmp(Dot d1,Dot d2){
	return d1.pos < d2.pos;
}
/***********************************************/
vector<Dot> dot;
vector<Dot> zone;
multiset<ll> lsh;
void add_dot(ll l,ll r,ll t){
	Dot d1,d2;
	d1.pos = l; d2.pos = r;
	d1.time = d2.time = t;
	d1.type = 1; d2.type = -1;
	dot.pb(d1); dot.pb(d2);
}
void add_zone(ll pos,int type){
	Dot d1;
	d1.pos = pos; d1.type = type;
	zone.pb(d1);
}
void zone_flush(){
	sort(dot.begin(),dot.end(),dot_cmp);
	
	for(ll i = 0;i < dot.size();i++){
		if(i > 0  &&  !lsh.empty()){
			ll s = *(lsh.begin());
			add_zone(s - dot[i].pos,1);
			add_zone(s - dot[i-1].pos,-1);
		}
		if(dot[i].type == 1) lsh.insert( dot[i].time );	//l 
		else lsh.erase(  lsh.find( dot[i].time )  );		//r 
	}
}
/***********************************************/
int main(){
//	freopen("inp.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> qq;
	for(uint i = 1;i <= qq;i++){
		ll l,r,t;
		cin >> l >> r >> t;
		add_dot(l,r,t);
	}
	
	zone_flush();
	
	for(uint qi = 1;qi <= n;qi++){
		ll q;
		cin >> q;
		add_zone( q , 0 );	//
	}
	
	sort(zone.begin(),zone.end(),dot_cmp);
	ll ans = 0;
	ll anss[500000] = {0};
	uint st = 0;
	int h = 0;
	for(uint i = 0;i < zone.size();i++){
		if(i > 0)
			ans += h * (zone[i].pos - zone[i-1].pos);
		if(zone[i].type == 0)
			anss[st++] = ans;
		h += zone[i].type;
	}
	
	for(uint ni = 0;ni < n;ni++)
		cout << anss[ni] << endl;
	
	return 0;
}