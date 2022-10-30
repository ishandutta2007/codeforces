#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;

struct Edge{
	int start , end , w;
}Ed[MAXN];
int A , B , fa[MAXN];
bool vis[MAXN];

bool operator <(Edge a , Edge b){
	return a.w > b.w;
}

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int A , B , ans = 0;
    cin >> A >> B;
    for(int i = 1 ; i <= B ; i++)
    	cin >> Ed[i].start >> Ed[i].end >> Ed[i].w;
    for(int i = 1 ; i <= A ; i++)
    	fa[i] = i;
    sort(Ed + 1 , Ed + B + 1);
    for(int i = 1 ; i <= B ; i++){
    	int p = find(Ed[i].start) , q = find(Ed[i].end);
    	if(p == q){
    		if(!vis[p]){
    			vis[p] = 1;
    			ans += Ed[i].w;
    		}
		}
		else
			if(!(vis[p] && vis[q])){
				fa[q] = p;
				vis[p] |= vis[q];
				ans += Ed[i].w;
			}
	}
	cout << ans;
	return 0;
}