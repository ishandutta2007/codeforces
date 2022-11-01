#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<deque>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,a) for(int i=a;i<(int)m;++i)
using namespace std;
typedef pair<int,int> pi;
#define fr first
#define sc second
#include<complex>
typedef long long int lint;
typedef complex<lint> P;
pair<P,int> p[200005];
int n,m;
bool cmp(const pair<P,int>& a,const pair<P,int>& b){
	if(a.fr.real()==b.fr.real()) return a.fr.imag()<b.fr.imag();
	return a.fr.real()<b.fr.real();
}
lint cross(P a,P b){
	return a.real()*b.imag()-a.imag()*b.real();
}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  return 0;
}
int main(){
	scanf("%d",&n);
	REP(i,n){
		cin>>p[i].fr.real()>>p[i].fr.imag();
		p[i].sc=1;
	}
	scanf("%d",&m);
	REP(i,m){
		cin>>p[i+n].fr.real()>>p[i+n].fr.imag();
		p[i+n].sc=0;
	}
	
	int n2=n+m;
	sort(p,p+n2,cmp);
	
  vector<pair<P,int> > ch(2*n2);
  int k=0;
  for (int i = 0; i < n2; ch[k++] = p[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2].fr, ch[k-1].fr, p[i].fr) < 0) --k;
  for (int i = n2-2, t = k+1; i >= 0; ch[k++] = p[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2].fr, ch[k-1].fr, p[i].fr) < 0) --k;
  ch.resize(k-1);
  REP(i,ch.size()){
		if(ch[i].sc==0){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}