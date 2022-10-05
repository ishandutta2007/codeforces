#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[101010],Y[101010],VX[101010],VY[101010];
long double DX[101010],DY[101010];

long double X1[101010],Y1[101010],X2[101010],Y2[101010];

int cross(int a,int b) {
	if(a==-1 || b==-1) return 0;
	if(a==N || b==N) return 0;
	int i;
	
	// on line
	FOR(i,2) {
		ll dx=X[a]-X[b];
		ll dy=Y[a]-Y[b];
		if(dx*VY[a]-dy*VX[a]==0) {
			if(min(X1[a],X2[a])<=X[b] && X[b]<=max(X1[a],X2[a]) && min(Y1[a],Y2[a])<=Y[b] && Y[b]<=max(Y1[a],Y2[a])) return 1;
			if(VX[a]*VY[b]-VX[b]*VY[a]==0) {
				if(min(X1[a],X2[a])<=X1[b] && X1[b]<=max(X1[a],X2[a]) && min(Y1[a],Y2[a])<=Y1[b] && Y1[b]<=max(Y1[a],Y2[a])) return 1;
				if(min(X1[a],X2[a])<=X2[b] && X2[b]<=max(X1[a],X2[a]) && min(Y1[a],Y2[a])<=Y2[b] && Y2[b]<=max(Y1[a],Y2[a])) return 1;
			}
		}
		swap(a,b);
		
	}
	if(VX[a]*VY[b]-VX[b]*VY[a]==0) return 0;
	
	long double eps=1e-14;
	FOR(i,2) {
		long double dx1=X2[a]-X1[a];
		long double dy1=Y2[a]-Y1[a];
		long double dx2=X1[b]-X1[a];
		long double dy2=Y1[b]-Y1[a];
		long double dx3=X2[b]-X1[a];
		long double dy3=Y2[b]-Y1[a];
		
		long double cr1=dx2*dy1-dx1*dy2;
		long double cr2=dx3*dy1-dx1*dy3;
		
		if(cr1<eps && cr2<eps) return 0;
		if(cr1>-eps && cr2>-eps) return 0;
		swap(a,b);
	}
	
	return 1;
	
}

long double CX;
bool cmp(int a, int b) {
	if(a==-1||b==N) return 1;
	if(a==N||b==-1) return 0;
	
	long double ay=Y[a]-DY[a]*(X[a]-CX)/DX[a];
	long double by=Y[b]-DY[b]*(X[b]-CX)/DX[b];
	if(ay==by) return a<b;
	return ay<by;
};
set<int, decltype(cmp)*> S(cmp);
decltype(S)::iterator preit[101010];

int ok(long double t) {
	int i;
	vector<pair<long double,int>> cand;
	FOR(i,N) {
		X1[i]=X[i];
		Y1[i]=Y[i];
		X2[i]=X[i]+DX[i]*t;
		Y2[i]=Y[i]+DY[i]*t;
		
		if(X1[i]>X2[i]) swap(X1[i],X2[i]),swap(Y1[i],Y2[i]);
		cand.push_back({X1[i],i});
		cand.push_back({X2[i],i+N});
	}
	sort(ALL(cand));
	S.clear();
	S.insert(-1);
	S.insert(N);
	//cout<<"------------"<<t<<endl;
	FORR(c,cand) {
		CX=c.first;
		/*cout<<c.first<<" "<<c.second<<" "<<N<<"  :";
		FORR(s,S) cout<<s<<" ";
		cout<<endl;*/
		if(c.second<N) {
			int a=c.second;
			
			auto it=S.lower_bound(a);
			//cout<<"comp "<<*prev(it)<<" "<<a<<" "<<*it<<endl;
			if(cross(a,*prev(it))) return 1;
			if(cross(a,*it)) return 1;
			preit[a]=S.insert(a).first;
		}
		else {
			int a=c.second-N;
			S.erase(preit[a]);
			auto it=S.lower_bound(a);
			//cout<<"comp "<<*prev(it)<<" "<<*it<<endl;
			if(cross(*prev(it),*it)) return 1;
		}
	}
	//cout<<"NG"<<t<<endl;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>VX[i]>>VY[i]>>r;
		long double d=hypot(VX[i],VY[i]);
		DX[i]=VX[i]/d*r;
		DY[i]=VY[i]/d*r;
	}
	
	long double L=0,R=1e10;
	if(ok(R)==0) return _P("No show :(\n");
	FOR(i,150) {
		long double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	//FOR(i,N) cout<<X1[i]<<" "<<Y1[i]<<" "<<X2[i]<<" "<<Y2[i]<<endl;
	_P("%.12lf\n",(double)L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}