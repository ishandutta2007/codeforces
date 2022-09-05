#include<bits/stdc++.h>
#define N 100003
using namespace std ;

int n , q , k , l , r , t , m1 , m2 , op , tot , v[N] , s[N * 2] , cnt[N * 2] , ans[N] ;
map<int , int> u ;
struct query{ int l , r , t , lk , rk , id ; }a[N] ;
struct modify{ int pos , v0 , v1 ; }b[N] ;

int uni(int x){ return u.count(x) ? u[x] : u[x] = ++ tot ; }
bool cmp(query a , query b)
{
	if(a.lk != b.lk) return a.lk < b.lk ;
	if(a.rk != b.rk) return a.rk < b.rk ;
	return a.t < b.t ;
}
void add(int x)
{
	s[cnt[x]] -- ;
	s[++ cnt[x]] ++ ;
}
void del(int x)
{
	s[cnt[x]] -- ;
	s[-- cnt[x]] ++ ;
}
void mo(int pos , int x)
{
	if(pos >= l && pos <= r)
	{
		add(x) ;
		del(v[pos]) ;
	}
	v[pos] = x ;
}
int get(int nl , int nr , int nt)
{
	while(t < nt){ ++ t ; mo(b[t].pos , b[t].v1) ; }
	while(t > nt){ mo(b[t].pos , b[t].v0) ; -- t ; }
	while(l < nl) del(v[l ++]) ;
	while(r > nr) del(v[r --]) ;
	while(l > nl) add(v[-- l]) ;
	while(r < nr) add(v[++ r]) ;
	int i ;
	for(i = 1 ; s[i] ; i ++) ;
	return i ;
}
int main()
{
	scanf("%d%d" , &n , &q) ;
	k = pow(n , 2.0/3) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d" , &v[i]) ;
		v[i] = uni(v[i]) ;
	}
	for(int i = 1 ; i <= q ; i ++)
	{
		scanf("%d%d%d" , &op , &l , &r) ;
		if(op == 1) a[++ m1] = (query){l , r , m2 , (l-1) / k , (r-1) / k , m1} ;
		else b[++ m2].pos = l , b[m2].v1 = uni(r) ;
	}
	for(int i = 1 ; i <= m2 ; i ++)
	{
		b[i].v0 = v[b[i].pos] ; 
		v[b[i].pos] = b[i].v1 ;
	}
	sort(a + 1 , a + m1 + 1 , cmp) ;
	t = m2 , l = 1 , r = 0 ;
	for(int i = 1 ; i <= m1 ; i ++)
	{
		ans[a[i].id] = get(a[i].l , a[i].r , a[i].t);
	}
	for(int i = 1 ; i <= m1 ; i ++) printf("%d\n" , ans[i]) ;
	return 0 ;
}