#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int n,x,cnt,a[210000],t[7100000][2];
vector<int> vec;
void insert(int &x,int y,int dep){
    if (!x){
		x=++cnt;
		t[x][0]=t[x][1]=0;
	} 
    if (dep==-1) return;
    insert(t[x][(y>>dep)&1],y,dep-1);
}
int query(int x,int y,int dep){
    if (dep==-1) return 0;
	int c=(y>>dep)&1;
    if (t[x][c]) return query(t[x][c],y,dep-1);
    else return query(t[x][c^1],y,dep-1)^(1<<dep);
}
ll solve(vector<int> v,int dep){
    if (!v.size()||dep==-1) return 0;
    vector<int> tmp[2];
	int ret=0,rt;
    for (int i:v) tmp[(i>>dep)&1].push_back(i);
    if (tmp[0].size()&&tmp[1].size()){
        ret=1<<(dep+1); rt=0; cnt=0;
        for (int i:tmp[0]) insert(rt,i,30);
        for (int i:tmp[1]) ret=min(ret,query(rt,i,30));
    }
    return ret+solve(tmp[0],dep-1)+solve(tmp[1],dep-1);
}
int main(){
    scanf("%d",&n); 
    for (int i=1;i<=n;i++){
		scanf("%d",&x);
		vec.push_back(x);
	}
    printf("%lld\n",solve(vec,30));
    return 0;
}