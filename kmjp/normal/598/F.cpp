#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

typedef complex<double> Po;

struct Line {
	Po a,b;
	Line(const Po &a,const Po &b) : a(a),b(b){Rep();};
	void Rep(){
		if(a.real()==b.real()) {
			a=Po(a.real(),0);
			b=Po(b.real(),1);
			return;
		} // Y-axis
		Po c,d;
		d=Po(1,(b.imag()-a.imag())/(b.real()-a.real()));
		c=Po(0,b.imag()-b.real()*d.imag());
		d=Po(1,d.imag()+c.imag());
		a=c; b=d;
	};
};

Po CrossPoint(const Line &l,const Line &r) {
	Po p,ld=l.b-l.a,rd=r.b-r.a,d3=l.b-r.a;
	double aa=ld.real()*rd.imag()-ld.imag()*rd.real();
	double bb=ld.real()*d3.imag()-ld.imag()*d3.real();
	if(abs(aa)<1e-9 && abs(bb)<1e-9) return Po(1e9,-1e9); //same
	if(abs(aa)<1e-9) return Po(1e9,1e9); //parallel
	return r.a+bb/aa*(r.b-r.a);
};

int N,M;
int X[1010],Y[1010];


ll comb(double a) {
	if(a==0) return 0;
	if(a>0) return a*100+0.1;
	if(a<0) return -(-a*100+0.1);
}

double hoge(ll sx,ll sy,ll dx,ll dy) {
	if(dx<0 || (dx==0 && dy<0)) sx+=dx, sy+=dy, dx=-dx, dy=-dy;
	pair<double,double> st={sx,sy};
	pair<double,double> ed={sx+dx,sy+dy};
	ll L=max(abs(dx),abs(dy));
	ll mul=100000000/L+2;
	
	pair<double,double> lst={sx-dx*mul,sy-dy*mul};
	pair<double,double> rst={sx+dx*mul,sy+dy*mul};
	
	vector<pair<pair<double,double>,int> > V;
	
	int i;
	FOR(i,N) {
		pair<double,double> a={X[i],Y[i]},b={X[i+1],Y[i+1]};
		ll dx2=X[i+1]-X[i],dy2=Y[i+1]-Y[i];
		
		ll ad=(X[i]-lst.first)*(rst.second-lst.second)-(Y[i]-lst.second)*(rst.first-lst.first);
		ll bd=(X[i+1]-lst.first)*(rst.second-lst.second)-(Y[i+1]-lst.second)*(rst.first-lst.first);
		if(dy*dx2==dx*dy2) {
			if(ad==0 && bd==0) {
				auto lef=max(st,min(a,b));
				auto ri=min(ed,max(a,b));
				V.push_back({lef,0});
				V.push_back({ri,0});
			}
		}
		else {
			
			if(ad>0&&bd>0) continue;
			else if(ad<0&&bd<0) continue;
			else if(ad==0) V.push_back({{X[i],Y[i]},(bd>0)?1:-1});
			else if(bd==0) V.push_back({{X[i+1],Y[i+1]},(ad>0)?-1:1});
			else {
				Po p1(lst.first,lst.second);
				Po p2(rst.first,rst.second);
				Po p3(X[i],Y[i]);
				Po p4(X[i+1],Y[i+1]);
				Line L1(p1,p2),L2(p3,p4);
				
				Po c=CrossPoint(L1,L2);
				V.push_back({{c.real(),c.imag()},(ad>0)?-2:2});
			}
			assert(ad||bd);
		}
	}
	sort(ALL(V));
	pair<double,double> pre=lst;
	int status=0;
	double len=0;
	FORR(r,V) {
		if(status) len += hypot(pre.first-r.first.first,pre.second-r.first.second);
		status+=r.second;
		pre=r.first;
	}
	
	return len;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		double dx,dy;
		cin>>dx>>dy;
		X[i]=comb(dx);
		Y[i]=comb(dy);
	}
	X[N]=X[0];
	Y[N]=Y[0];
	FOR(r,M) {
		double tx1,ty1,tx2,ty2;
		cin>>tx1>>ty1>>tx2>>ty2;
		_P("%.12lf\n",hoge(comb(tx1),comb(ty1),comb(tx2)-comb(tx1),comb(ty2)-comb(ty1))/100.0);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}