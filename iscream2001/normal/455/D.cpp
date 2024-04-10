#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=1e5+10;

void init(){
	
}
const int E=400;
int n,m,lastans;
deque<int> a[400];
int cnt[N][400];
void Encode(int &x){
	x=(x+lastans-1)%n+1;
}
void MAIN(){
	int op,l,r,x,y,z,L,R;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		a[i/E].push_back(x);
		cnt[x][i/E]++;
	}
	scanf("%d",&m);
	lastans=0;
	while(m--){
		scanf("%d%d%d",&op,&l,&r);
		Encode(l);Encode(r);
		--l;--r;
		if(l>r) swap(l,r);
		L=l/E;R=r/E;
		if(op==1){
			if(L==R){
				x=a[L][r%E];
				a[L].erase(a[L].begin()+r%E);
				a[L].insert(a[L].begin()+l%E,x);
			}
			else{
				for(int i=L;i<R;){
					x=a[i].back();
					a[i].pop_back();
					cnt[x][i]--;
					++i;
					a[i].push_front(x);
					cnt[x][i]++;
				}
				x=a[R][r%E+1];
				a[R].erase(a[R].begin()+r%E+1);
				cnt[x][R]--;
				a[L].insert(a[L].begin()+l%E,x);
				cnt[x][L]++;
			}
		}
		else{
			scanf("%d",&x);Encode(x);
			lastans=0;
			z=r%E;
			//cout<<z<<endl;
			if(L==R){
				for(int i=l%E;i<=z;++i){
					lastans+=(a[L][i]==x);
				}
			}
			else{
				for(int i=L+1;i<R;++i){
					lastans+=cnt[x][i];
				}
				for(int i=l%E;i<E;++i){
					lastans+=(a[L][i]==x);
				}
				for(int i=0;i<=z;++i){
					lastans+=(a[R][i]==x);
				}
			}
			printf("%d\n",lastans);
		}
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}