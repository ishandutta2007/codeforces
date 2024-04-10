#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<complex>
#include<map>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
typedef complex<lint> P;
#define X real()
#define Y imag()
namespace std{
	bool operator <(const P& a,const P& b){
		return a.X!=b.X ? a.X<b.X:a.Y<b.Y;
	}
};


typedef vector<lint> vi;
typedef pair<P,lint> line;
int n,m;
pair<P,P> seg[300005];
map<line,pair<vi,vi> > groupp;
lint cross(P a,P b){
	return a.real()*b.imag()-a.imag()*b.real();
}

lint gcd(lint a,lint b){
	a=abs(a);b=abs(b);
	if(a>b) swap(a,b);
	while(a){
		b%=a;
		swap(a,b);
	}
	return b;
}
line make(P a,P b){
	if(b<a) swap(a,b);
	P dif=b-a;
	lint prod=cross(a,b);
	lint g=gcd(dif.X,dif.Y);
	prod/=g;
	dif/=g;

	return mp(dif,prod);
}

lint getpos(line l,P a){
	return l.fr.X*a.X+l.fr.Y*a.Y;
}

pair<P,lint> circ[2000];
int count(const vector<lint>& a,lint val){
	return upper_bound(ALL(a),val)-a.begin();
}

int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>seg[i].fr.X>>seg[i].fr.Y>>seg[i].sc.X>>seg[i].sc.Y;
		seg[i].fr*=2ll;
		seg[i].sc*=2ll;
		line tl=make(seg[i].fr,seg[i].sc);
		lint p1=getpos(tl,seg[i].fr),p2=getpos(tl,seg[i].sc);
		if(p1>p2) swap(p1,p2);
		groupp[tl].fr.pb(p1);
		groupp[tl].sc.pb(p2);
	}
	for(map<line,pair<vi,vi> >::iterator it=groupp.begin();it!=groupp.end();++it){
		sort(ALL(it->sc.fr));
		sort(ALL(it->sc.sc));
	}

	REP(i,m){
		cin>>circ[i].fr.X>>circ[i].fr.Y>>circ[i].sc;
		circ[i].fr*=2ll;
		circ[i].sc*=2;
	}
	
	lint res=0;
	REP(i,m) REP(j,i) if(circ[i].sc==circ[j].sc){
		P mid=(circ[i].fr+circ[j].fr)/2ll;
		P dif=circ[j].fr-circ[i].fr;
		if(norm(dif)<=4*circ[i].sc*circ[i].sc) continue;
		P vert=P(-dif.Y,dif.X);
		P p2=mid+vert;

		line tl=make(mid,p2);
		if(groupp.count(tl)){
			map<line,pair<vi,vi> >::iterator it=groupp.find(tl);
			lint Mpos=getpos(tl,mid);
			res+=count(it->sc.fr,Mpos)-count(it->sc.sc,Mpos-1);
		}
	}
	cout<<res<<endl;
	return 0;
}