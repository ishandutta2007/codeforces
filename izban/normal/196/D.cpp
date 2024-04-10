#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll int

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=1<<19;
const ll q=(1e9)+7;


int d,n;
ll p[maxn];
string s1,s2;
//ll t1[4*maxn], t2[4*maxn];

vector<ll> t1,t2;

void init (int nn, vector<ll> &t)
{
	n = nn;
	t.assign (n, 0);
}

int sum (int r, vector<ll> &t)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, ll delta, vector<ll> &t)
{
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r, vector<ll> &t)
{
	return sum (r,t) - sum (l-1,t);
}

void init (vector<int> a, vector<ll> &t)
{
	init ((int) a.size(),t);
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i], t);
}

void upd(ll *t, int v, int tl, int tr, int x, int y) {
	if (tl==tr) {
		t[v]=y*p[x];
		return;
	}
	int tm=(tl+tr)>>1;
	if (x<=tm) upd(t,v*2,tl,tm,x,y);
	else upd(t,v*2+1,tm+1,tr,x,y);
	t[v]=t[v*2]+t[v*2+1];
}

ll get(ll *t, int v, int tl, int tr, int l, int r) {
	if (l>r) return 0;
	if (l==tl && r==tr) {
		return t[v];
	}
	int tm=(tl+tr)>>1;
	return get(t,v*2,tl,tm,l,min(r,tm))+get(t,v*2+1,tm+1,tr,max(l,tm+1),r);
}

bool bad(int i, int j) {
	ll h1,h2;
	//h1=get(t1,1,0,n-1,i,j); h1*=p[maxn-i-1];
	//h2=get(t2,1,0,n-1,n-1-j,n-1-i); h2*=p[maxn-(n-1-j)-1];
	h1=sum(i,j,t1); h1*=p[maxn-i-1];
	h2=sum(n-1-j,n-1-i,t2); h2*=p[maxn-(n-1-j)-1];
	return h1==h2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	p[0]=1; for (int i=1; i<maxn; i++) p[i]=p[i-1]*q;

	cin >> d >> s1;
	s2=string(s1.rbegin(),s1.rend());
	n=s1.length();
	init(n,t1); init(n,t2);

	
	for (int i=0; i<n; i++) {
		//upd(t1,1,0,n-1,i,s1[i]-'a');
		//upd(t2,1,0,n-1,i,s2[i]-'a');
		inc(i,(s1[i]-'a')*p[i],t1);
		inc(i,(s2[i]-'a')*p[i],t2);
	}

	int pos=s1.length()-1;

	for (int i=0; i<n; i++) {
		if (i+d-1<n && bad(i,i+d-1)) 
			pos=min(pos,i+d-1);
		if (i+d<n && bad(i,i+d))
			pos=min(pos,i+d);
	}

	bool f=false;
	while (pos>=0) {
		do {
			if (s1[pos]=='z') break;
			s1[pos]++;
			//upd(t1,1,0,n-1,pos,s1[pos]-'a');
			//upd(t2,1,0,n-1,n-1-pos,s1[pos]-'a');
			inc(pos,p[pos],t1);
			inc(n-1-pos,p[n-1-pos],t2);
			f=true;
			if (pos-d+1>=0 && bad(pos-d+1,pos)) f=false;
			if (pos-d>=0 && bad(pos-d,pos)) f=false;
		} while (!f);
		
		if (f) break; 
		else pos--;
	}

	if (pos==-1) {
		cout << "Impossible" << endl;
		return 0;
	}

	for (int i=pos+1; i<n; i++) {
		//s1[i]=s2[n-1-i]='a';
		//upd(t1,1,0,n-1,i,s1[i]-'a');
		//upd(t2,1,0,n-1,n-1-i,s1[i]-'a');
		inc(i,('a'-s1[i])*p[i],t1);
		inc(n-1-i,('a'-s1[i])*p[n-1-i],t2);
		s1[i]=s2[n-1-i]='a';

		while ((i-d+1>=0 && bad(i-d+1,i)) || (i-d>=0 && bad(i-d,i))) {
			s1[i]++; s2[n-1-i]++;
			//upd(t1,1,0,n-1,i,s1[i]-'a');
			//upd(t2,1,0,n-1,n-1-i,s1[i]-'a');
			inc(i,p[i],t1);
			inc(n-1-i,p[n-1-i],t2);
		}
	}
	
	cout << s1 << endl;
	return 0;
}