#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],b[100500],pos[100500],res[100500];
ll x;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < m)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

bitset<100005> b0,b1,sb;

int main(){
	scanf("%d%d%lld",&n,&m,&x);
	initAB();
	for(i=0;i<n;i++){
		b0[i]=b[i];
		pos[a[i]]=i;
	}
	b1.set();
	for(i=n;i>=1;i--){
		sb=((b0<<(pos[i]))&b1);
		for(j=sb._Find_first();j!=sb.size();j=sb._Find_next(j)){
			res[j]=i;b1[j]=0;
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",res[i]);
	}
}