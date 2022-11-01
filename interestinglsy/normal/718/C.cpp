#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define MOD 1000000007
#define INF 99999999
#define uint unsigned int
#define ll long long
#define ull unsigned ll
#define sint short int
#define ms(d) memset(d,0,sizeof(d))
using namespace std;

uint n,q;

////////////////////////////////////////////////////////////////////    
ll add(ll a,ll b){    ll c=a+b;    return c % MOD;    }
ll mult(ll a,ll b){    ll c=a*b;    return c % MOD;    }
////////////////////////////////////////////////////////////////////
class Matrix{
public:
	ll num[3][3];
	friend ostream &operator<<(ostream &os,const Matrix &m1);
};
Matrix get1(){
	Matrix m1;
	m1.num[1][1] = m1.num[2][2] = 1;
	m1.num[2][1] = m1.num[1][2] = 0;
	return m1;
}
Matrix f1(){
	Matrix m1;
	m1.num[2][2] = 0;
	m1.num[1][1] = m1.num[2][1] = m1.num[1][2] = 1;
	return m1;
}
Matrix madd(Matrix m1,Matrix m2){
	Matrix m3 = get1();
	m3.num[1][1] = add( m1.num[1][1] , m2.num[1][1] );
	m3.num[2][1] = add( m1.num[2][1] , m2.num[2][1] );
	m3.num[1][2] = add( m1.num[1][2] , m2.num[1][2] );
	m3.num[2][2] = add( m1.num[2][2] , m2.num[2][2] );
	return m3;
}
Matrix mmult(Matrix m1,Matrix m2){
	Matrix m3 = get1();
	for(uint i = 1;i <= 2;i++)
		for(uint j = 1;j <= 2;j++){
			m3.num[i][j] = 0;
			for(uint k = 1;k <= 2;k++)
				m3.num[i][j] = add(    m3.num[i][j]    ,    mult( m1.num[i][k] , m2.num[k][j] )    );
		}
	return m3;
}
Matrix mpow(Matrix m1,ll p){
	if(p == 0) return get1();
	if(p == 2   ||   p & 1) return mmult( m1 , mpow(m1,p-1) );
	else return mpow(mpow(m1,p >> 1) , 2);
}
////////////////////////////////////////////////////////////////////
Matrix tree[500020];
Matrix lazy[500020];
ll inp[500020];
void push(ll pos){
	tree[pos*2] = mmult(  tree[pos*2]  ,  lazy[pos]  );
	tree[pos*2+1] = mmult(  tree[pos*2+1]  ,  lazy[pos]  );
	lazy[pos*2] = mmult(  lazy[pos*2]  ,  lazy[pos]  );
	lazy[pos*2+1] = mmult(  lazy[pos*2+1]  ,  lazy[pos]  );
	lazy[pos] = get1();
}
void update(ll pos){
	tree[pos] = madd(  tree[pos*2]  ,  tree[pos*2+1]  );
}
void build(ll l,ll r,ll pos){
	if(l == r) tree[pos] = mpow(f1(),inp[l]);
	else{
		ll mid = (l+r) >> 1;
		build(l,mid,pos*2);
		build(mid+1,r,pos*2+1);
		update(pos);
	}
}
void inc(ll gl,ll gr,ll l,ll r,ll pos,Matrix x){
	if(gl <= l  &&  r <= gr){
		tree[pos] = mmult(tree[pos],x);
		lazy[pos] = mmult(lazy[pos],x);
		return;
	}
	if(gl > r  ||  gr < l) return;
	push(pos);
	ll mid = (l+r) >> 1;
	inc(gl,gr,l,mid,pos*2,x);
	inc(gl,gr,mid+1,r,pos*2+1,x);
	update(pos);
}
Matrix sum(ll gl,ll gr,ll l,ll r,ll pos){
	if(gl <= l  &&  r <= gr) return tree[pos];
	if(gl > r  ||  gr < l) return get1();
	push(pos);
	ll mid = (l+r) >> 1;
	return madd(   sum(gl,gr,l,mid,pos*2)  ,  sum(gl,gr,mid+1,r,pos*2+1)  );//madd(   madd( sum(gl,gr,l,mid,pos*2) , sum(gl,gr,mid+1,r,pos*2+1)  )    ,    lazy[pos]   );
}
////////////////////////////////////////////////////////////////////
ostream & operator<<(ostream &os,const Matrix &m1){
    os << m1.num[2][1];
    return os;
}
void show(){
	cout << tree[1] << endl;
	cout << tree[2] << "\t" << tree[3] << endl;
	//cout << tree[4] << "\t" << tree[5] << "\t" << tree[6] << "\t" << tree[7] << endl;
	//cout << tree[8] << "\t" << tree[9] << "\t" << tree[10] << "\t" << tree[11] << "\t" << tree[12] << "\t" << tree[13] << "\t" << tree[14] << "\t" << tree[15] << endl;
}
int main(){
	//freopen("inp.txt","r",stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(uint i = 1;i <= 2*n;i++){
		inp[i] = 0;
		lazy[i] = get1();
		tree[i] = get1();
	}
	for(uint i = 1;i <= n;i++)
		cin >> inp[i];
	
	build(1,n,1);
	//show();
	for(uint qi = 1;qi <= q;qi++){
		sint cmd;
		cin >> cmd;
		if(cmd == 1){
			ll l,r,x;
			cin >> l >> r >> x;
			inc(l,r,1,n,1,mpow(f1(),x));
		}else{
			ll l,r;
			cin >> l >> r;
			Matrix ans = sum(l,r,1,n,1);
			cout << ans << endl;
		}
	}
}