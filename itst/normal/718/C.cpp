#include<bits/stdc++.h>
#define MAXN 100001
#define MOD 1000000007
#define ll long long
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c)){
        a = (a << 3) + (a << 1) + (c ^ '0');
        c = getchar();
    }
    return a;
}

struct matrix{
    ll a[2][2];
    matrix(int f = 0 , int b = 0 , int c = 0 , int d = 0){
        a[0][0] = f;
        a[0][1] = b;
        a[1][0] = c;
        a[1][1] = d;
    }
    ll* operator [](int x){
        return a[x];
    }
    matrix operator +(matrix b){
        matrix c;
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 0 ; j < 2 ; j++)
                c[i][j] = (a[i][j] + b[i][j]) % MOD;
        return c;
    }
    matrix operator *(matrix b){
        matrix c;
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 0 ; j < 2 ; j++)
                for(int k = 0 ; k < 2 ; k++)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        return c;
    }
}Tree[MAXN << 2] , ad[MAXN << 2] , G(1,1,1) , S , T , e(1,0,0,1);

inline matrix ksm(int a){
    S = e;
    T = G;
    while(a){
        if(a & 1)
            S = S * T;
        T = T * T;
        a >>= 1;
    }
    return S;
}

void init(int l , int r , int now){
	ad[now] = e;
	if(l == r){
		Tree[now] = e;
		return;
	}
	init(l , l + r >> 1 , now << 1);
	init((l + r >> 1) + 1 , r , now << 1 | 1);
	Tree[now] = Tree[now << 1] + Tree[now << 1 | 1];
}

inline void pushdown(int dir){
    Tree[dir << 1] = Tree[dir << 1] * ad[dir];
    Tree[dir << 1 | 1] = Tree[dir << 1 | 1] * ad[dir];
    ad[dir << 1] = ad[dir << 1] * ad[dir];
    ad[dir << 1 | 1] = ad[dir << 1 | 1] * ad[dir];
    ad[dir] = e;
}

void add(int now , int l , int r , int L , int R , matrix k){
    if(l >= L && r <= R){
        Tree[now] = Tree[now] * k;
        ad[now] = ad[now] * k;
        return; 
    }
    pushdown(now);
    if(l + r >> 1 >= L)
        add(now << 1 , l , l + r >> 1 , L , R , k);
    if(l + r >> 1 < R)
        add(now << 1 | 1 , (l + r >> 1) + 1 , r , L , R , k);
    Tree[now] = Tree[now << 1] + Tree[now << 1 | 1];
}

matrix getSum(int now , int l , int r , int L , int R){
    if(l >= L && r <= R)
        return Tree[now];
    pushdown(now);
    matrix k;
    if(l + r >> 1 >= L)
        k = k + getSum(now << 1 , l , l + r >> 1 , L , R);
    if(l + r >> 1 < R)
        k = k + getSum(now << 1 | 1 , (l + r >> 1) + 1 , r , L , R);
    return k;
}

int main(){
    int N = read() , M = read();
    init(1 , N , 1);
	for(int i = 1 ; i <= N ; i++)
        add(1 , 1 , N , i , i , ksm(read() - 1));
    while(M--)
        if(read() == 1){
            int a = read() , b = read() , c = read();
            add(1 , 1 , N , a , b , ksm(c));
        }
        else{
            int a = read() , b = read();
            cout << getSum(1 , 1 , N , a , b)[0][0] << endl;
        }
    return 0;
}