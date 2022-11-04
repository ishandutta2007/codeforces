#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    bool rev;
    bool inv;
    pitem l, r;
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
    if(it&&it->inv) {
		it->inv=false;
		it->value=1-it->value;
		if(it->l) it->l->inv^=true;
		if(it->r) it->r->inv^=true;
	}
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    t2->inv ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cerr<<t->value<<" ";
    //printf ("%d ", t->value);
    output (t->r);
}


int at_pos(pitem& root, int x) {
	pitem t1=NULL, t2=NULL, t3=NULL;
	split(root, t1, t2, x);

	split(t2, t2, t3, 1);
	
	int val=t2->value;
	
	merge(root, t1, t2);
	merge(root, root, t3);

	return val;
	
}

int main() {
	IO;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> A,B;
		string a,b;
		cin>>a>>b;
		
		for(auto i:a) A.pb(i-'0');
		for(auto i:b) B.pb(i-'0');
		
		pitem root=new item{uniform_int_distribution<int>(0, 2e9)(rng), A[0], 0, false, false, 0, 0};
		for(int i=1;i<sz(A);++i) {
			pitem akt=new item{uniform_int_distribution<int>(0, 2e9)(rng), A[i], 0, false, false, 0, 0};
			merge(root, root, akt);
		}
		/*output(root);cerr<<"\n";
		reverse(root,0,0);
		output(root);
		exit(0);*/
		vector<int> ans;
		for(int i=sz(B)-1;i>=0;i--) {
			if(B[i]==(at_pos(root, 0)^1)) {
				ans.pb(i+1);
				reverse(root, 0, i);
			}else {
				ans.pb(1);
				reverse(root, 0, 0);

				ans.pb(i+1);				
				reverse(root, 0, i);
			}
	
	//		output(root);cerr<<"\n";
		//	for(int j=0;j<sz(A);++j) cerr<<at_pos(root, j)<<" \n"[j==sz(A)-1];
		}

		cout<<sz(ans);
		for(auto i:ans) {
			cout<<" "<<i;
		}cout<<"\n";
		
	}
	return 0;
}