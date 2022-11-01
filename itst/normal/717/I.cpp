#include<bits/stdc++.h>
using namespace std;

#define ld double
#define eps 1e-8
ld cmp(ld p , ld q){return p + eps > q && p - eps < q;}
const int _ = 1e5 + 7;
struct vec{
	ld x , y , z;
	vec(ld _x = 0 , ld _y = 0 , ld _z = 0) : x(_x) , y(_y) , z(_z){}
	friend vec operator +(vec p , vec q){return vec(p.x + q.x , p.y + q.y , p.z + q.z);}
	friend vec operator -(vec p , vec q){return vec(p.x - q.x , p.y - q.y , p.z - q.z);}
	friend vec operator *(vec p , ld q){return vec(p.x * q , p.y * q , p.z * q);}
	friend vec operator /(vec p , ld q){return vec(p.x / q , p.y / q , p.z / q);}
	friend ld operator *(vec p , vec q){return p.x * q.x + p.y * q.y + p.z * q.z;}
	friend vec operator %(vec p , vec q){return vec(p.y * q.z - p.z * q.y , p.z * q.x - p.x * q.z , p.x * q.y - p.y * q.x);}
	ld len(){return sqrt(*this * *this);}
}p1[_] , p2[_];

struct line{vec st , pos; line(vec _s = vec() , vec _p = vec()) : st(_s) , pos(_p){}};
struct flat{vec st , nor; flat(){} flat(vec a , vec b , vec c){st = a; nor = (b - a) % (c - a);}};

vec sect(line p , line q){return q.st + q.pos * (p.pos % (q.st - p.st)).len() / (q.pos % p.pos).len();}
ld dist(vec p , flat q){return (p - q.st) * q.nor / q.nor.len();}

vec sect(line p , flat q){
	vec A = p.st , B = p.st + p.pos; ld da = dist(A , q) , db = dist(B , q);
	assert(!cmp(da , db)); ld l = da / (da - db); return A + p.pos * l;
}

line sect(flat p , flat q){
	line s; s.pos = p.nor % q.nor; vec linep = p.nor % vec(77077 , 12449 , 13888);
	s.st = sect(line(p.st , linep) , q); return s;
}

int N , M; line sct;

int Count(vector < vec > &x , vector < vec > &y){
	auto cmp = [&](vec p , vec q){return (q - p) * sct.pos < 0;};
	sort(x.begin() , x.end() , cmp); sort(y.begin() , y.end() , cmp);
	int cnt = 0 , t1 = 0 , t2 = 0;
	while(t1 < x.size() || t2 < y.size())
		if(t1 < x.size() && (t2 == y.size() || cmp(x[t1] , y[t2]))) ++t1;
		else{cnt += t1 & 1; ++t2;}
	return cnt;
}

int main(){
	scanf("%d" , &N); for(int i = 1 ; i <= N ; ++i) scanf("%lf %lf %lf" , &p1[i].x , &p1[i].y , &p1[i].z);
	scanf("%d" , &M); for(int i = 1 ; i <= M ; ++i) scanf("%lf %lf %lf" , &p2[i].x , &p2[i].y , &p2[i].z);
	flat pol1(p1[1] , p1[2] , p1[3]) , pol2(p2[1] , p2[2] , p2[3]);
	if(cmp((pol1.nor % pol2.nor).len() , 0)){puts("NO"); return 0;}
	sct = sect(pol1 , pol2);


#define nxt(x) (x % N + 1)
	int pos = 1 , tmp; while(pos < N && cmp(0 , pol2.nor * (p1[pos] - pol2.st))) ++pos;
	tmp = nxt(pos); ld pre = pol2.nor * (p1[pos] - pol2.st); vector < vec > imp;
	do{
		ld cur = pol2.nor * (p1[tmp] - pol2.st);
		if(cur * pre < -eps){pre = cur; imp.push_back(sect(sct , line(p1[tmp] , p1[tmp == 1 ? N : tmp - 1] - p1[tmp])));}
	}while((tmp = nxt(tmp)) != nxt(pos));

#undef nxt
#define nxt(x) (x % M + 1)	
	
	pos = 1; while(pos < M && cmp(0 , pol1.nor * (p2[pos] - pol1.st))) ++pos;
	tmp = nxt(pos); pre = pol1.nor * (p2[pos] - pol1.st); vector < vec > imp1[2]; bool flg = 0;
	do{
		ld cur = pol1.nor * (p2[tmp] - pol1.st);
		if(cur * pre < -eps){pre = cur; imp1[flg ^= 1].push_back(sect(sct , line(p2[tmp] , p2[tmp == 1 ? M : tmp - 1] - p2[tmp])));}
	}while((tmp = nxt(tmp)) != nxt(pos));
	
	puts(Count(imp , imp1[0]) != Count(imp , imp1[1]) ? "YES" : "NO"); return 0;
}