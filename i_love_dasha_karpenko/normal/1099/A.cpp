#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define INF 10000000000007
typedef pair<long,long> pairll;
long long w,h,u,d,u1,d1;
int main() {
    //freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	cin>>w>>h>>u>>d>>u1>>d1;
	for (int i = h;i>=0;i--){
        w+=i;
        if (i==d){
            w-=u;
            if (w<0)w=0;
        }
        if (i==d1){
            w-=u1;
            if (w<0)w=0;
        }
	}
    cout<<w;
}