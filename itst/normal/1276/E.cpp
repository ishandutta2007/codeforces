#include<cstdio>
//STL
#include<algorithm>
#include<vector>
using namespace std;

#define int long long
vector < int > A , B; int d , g;
void init(){
	int g1 = 0 , g2 = 0; sort(A.begin() , A.end()); sort(B.begin() , B.end());
	for(int i = 1 ; i < 4 ; ++i){g1 = __gcd(g1 , A[i] - A[i - 1]); g2 = __gcd(g2 , B[i] - B[i - 1]);}
	if(!g1 && !g2){printf("%d\n" , (A[0] == B[0] ? 0 : -1)); exit(0);}
	if(g1 != g2){puts("-1"); exit(0);}
	if(A[0] % g1 != B[0] % g1){puts("-1"); exit(0);}
	d = A[0] % g1; g = g1; int cnt = 0;
	for(auto &t : A) cnt += (t = (t - d) / g) & 1;
	for(auto &t : B) cnt -= (t = (t - d) / g) & 1;
	if(cnt){puts("-1"); exit(0);}
}

vector < pair < int , int > > s1 , s2;

void move(vector < int > &p , int x , int y , int id){
	if(p[x] == p[y]) return;
	if(id == 1){s1.push_back(make_pair(p[x] , p[y])); p[x] = 2 * p[y] - p[x];}
	else{s2.push_back(make_pair(p[x] = 2 * p[y] - p[x] , p[y]));}
}

void work1(vector < int > &p , int id){
	while(p[3] - p[0] > 1){
		int delt = (p[3] - p[0] + 3) / 4;
		auto dist = [&](int x){return min(x - p[0] , p[3] - x);};
		int d1 = dist(p[1]) , d2 = dist(p[2]);
		while(d1 < delt && d2 < delt){
			if(d1 < d2)
				if(p[2] - p[0] < p[3] - p[2]){move(p , 1 , 0 , id); move(p , 1 , 2 , id);}
				else{move(p , 1 , 2 , id); move(p , 1 , 3 , id);}
			else
				if(p[1] - p[0] < p[3] - p[1]){move(p , 2 , 1 , id); move(p , 2 , 0 , id);}
				else{move(p , 2 , 3 , id); move(p , 2 , 1 , id);}
			sort(p.begin() , p.end()); d1 = dist(p[1]); d2 = dist(p[2]);
		}
		if(d1 >= delt)
			if(p[3] - p[1] >= p[1] - p[0]) move(p , 0 , 1 , id);
			else{move(p , 3 , 1 , id); move(p , 2 , 1 , id);}
		else
			if(p[3] - p[2] >= p[2] - p[0]) move(p , 3 , 2 , id);
			else{move(p , 0 , 2 , id); move(p , 1 , 2 , id);}
		sort(p.begin() , p.end());
	}
}

void work2(vector < int > &A , vector < int > &B , int id){
	auto extend = [&](){move(A , 2 , 0 , id); move(A , 1 , 3 , id); sort(A.begin() , A.end());};
	auto ixtend = [&](){move(A , 0 , 1 , id); move(A , 3 , 2 , id); sort(A.begin() , A.end());};
	auto shift = [&](){
		move(A , 1 , 0 , id); move(A , 2 , 0 , id);
		for(int i = 0 ; i < 3 ; ++i) move(A , i , 3 , id);
		move(A , 3 , 0 , id); sort(A.begin() , A.end());
	};
	int length = (B[0] - A[0]) / 2; while(A.back() - A[0] < length) extend();
	while(1){
		while(length >= A.back() - A[0]){length -= A.back() - A[0]; shift();}
		if(A.back() - A[0] == 1) break; else ixtend();
	}
}

signed main(){
	for(int i = 0 ; i < 4 ; ++i){int x; scanf("%lld" , &x); A.push_back(x);}
	for(int i = 0 ; i < 4 ; ++i){int x; scanf("%lld" , &x); B.push_back(x);}
	init(); sort(A.begin() , A.end()); sort(B.begin() , B.end()); work1(A , 1); work1(B , -1);
	int p = 0; while(A[p] & 1) move(A , p++ , 3 , 1);
	p = 0; while(B[p] & 1) move(B , p++ , 3 , -1);
	sort(A.begin() , A.end()); sort(B.begin() , B.end());
	if(A[0] < B[0]) work2(A , B , 1); else work2(B , A , -1);
	reverse(s2.begin() , s2.end()); printf("%d\n" , s1.size() + s2.size());
	for(auto t : s1) printf("%lld %lld\n" , t.first * g + d , t.second * g + d);
	for(auto t : s2) printf("%lld %lld\n" , t.first * g + d , t.second * g + d);
	return 0;
}