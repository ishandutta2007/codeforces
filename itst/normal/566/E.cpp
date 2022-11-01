#include<bits/stdc++.h>
#define P pair < int , int >
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1010;
vector < P > Edge;
bitset < MAXN > neigh[MAXN] , mod[MAXN] , jz[MAXN] , nleaf , vis , in , temp;
int N;

inline int bina(bitset < MAXN > a){
	int L = 1 , R = N;
	while(L < R){
		int mid = L + R >> 1;
		(a & mod[mid]).any() ? R = mid : L = mid + 1;
	}
	return L;
}

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		mod[i] = mod[i - 1];
		mod[i].set(i);
	}
	for(int i = 1 ; i <= N ; ++i){
		jz[i].set(i);
		for(int K = read() ; K ; --K)
			neigh[i].set(read());
	}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i + 1 ; j <= N ; ++j)
			if((temp = neigh[i] & neigh[j]).count() == 2){
				int u = bina(temp);
				temp.reset(u);
				int v = bina(temp);
				if(!jz[u][v]){
					in[u] = in[v] = jz[u][v] = jz[v][u] = vis[u] = vis[v] = 1;
					Edge.push_back(P(u , v));
				}
			}
	if(vis.none())
		for(int i = 2 ; i <= N ; ++i)
			printf("1 %d\n" , i);
	else{
		for(int i = 1 ; i <= N ; ++i)
			for(int j = 1 ; j <= N ; ++j)
				if((neigh[i] & neigh[j]) == neigh[i] && (neigh[i] & neigh[j]) != neigh[j])
					nleaf.set(j);
		for(int i = 1 ; i <= N ; ++i)
			if(!nleaf[i]){
				int u = bina(neigh[i] ^ (vis & neigh[i]));
				vis[u] = 1;
				temp = in & neigh[i];
				if(temp.count() == 2){
					int p = bina(temp);
					temp.reset(p);
					int q = bina(temp);
					if(jz[p].count() == 2 && jz[q].count() == 2){
						temp = neigh[i] ^ (in & neigh[i]);
						for(int i = 1 ; i <= N ; ++i)
							if(i != p && i != q)
								if(temp[i])
									printf("%d %d\n" , p , i);
								else
									printf("%d %d\n" , q , i);
						printf("%d %d\n" , p , q);
						return 0;
					}
					else
						Edge.push_back(P(jz[p].count() == 2 ? p : q , u));
				}
				else
					while(temp.any()){
						int t = bina(temp);
						if(jz[t] == (in & neigh[i])){
							Edge.push_back(P(t , u));
							break;
						}
						temp.reset(t);
					}
			}
		for(int i = 0 ; i < N - 1 ; ++i)
			printf("%d %d\n" , Edge[i].first , Edge[i].second);
	}
	return 0;
}