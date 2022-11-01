#include <cmath>
#include <queue> 
#include <cstdio> 
#include <vector> 
#include <cstring> 
#include <iostream> 
#define pa pair <int,int>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define inf 1000000000
#define ms(lsy) memset(lsy,0,sizeof(lsy))
#define ms2(ls,y) memset(ls,y,sizeof(ls))
#define ll long long 
using namespace std;


int m , n;
int mn[100005] , mx[100005];
bool vis[100005] , inq[100005];
vector <int> u[100005] , v[100005];
priority_queue <pa,vector <pa>,greater <pa> > q;
struct data{
    int id , w , r , sum;
    vector <int> v;
}p[100005];


void dijkstra(){
    ms2(mn,127);
    while(!q.empty()){
        int d = min(inf , q.top().first);
		int x = q.top().second;
		q.pop();
        if(d < mn[x]){           
            for(int i = 0;i < v[x].size();i++){
                int t = v[x][i];
                if(mn[x] > inf)
					p[t].r--,p[t].sum += d;
                else 
					p[t].sum += d-mn[x];
                if(!p[t].r)
					q.push(mp(p[t].sum , p[t].id));
                p[t].sum = min(p[t].sum , inf);
            }
            mn[x] = d;
        }
    }
    for(int i = 1;i <= n;i++)
        if(mn[i] > inf)mn[i] = mx[i] = -1;
}


void dp(int x){
    if(vis[x] || inq[x])return;
    vis[x] = inq[x] = 1;
    for(int i = 0;i < u[x].size();i++){
        int t = u[x][i] , sum = p[t].w;
        for(int j = 0;j < p[t].v.size();j++)
            if(mx[p[t].v[j]] == -1){sum = -1;break;}
        if(sum == -1)continue;
        for(int j = 0;j < p[t].v.size();j++){
            int v = p[t].v[j];
            dp(v);
            if(inq[v] || mx[v] == inf){sum = inf;break;}
            sum += mx[v];
        }
        mx[x] = max(mx[x] , sum);
    }
    inq[x] = 0;
}


int main(){
	//freopen("325C.txt","r",stdin);
    cin >> m >> n; 
    for(int i = 1;i <= m;i++){
        cin >> p[i].id;u[p[i].id].pb(i);
        int x , y;
        cin >> x;
        for(int j = 1;j <= x;j++){
            cin >> y;
            if(y == -1) p[i].w++;
            else {
                p[i].r++;
                p[i].v.pb(y);
				v[y].pb(i);
            }
        }
        if(p[i].w == x)q.push(mp(p[i].w , p[i].id));
        p[i].sum = p[i].w;
    }
    dijkstra();
    for(int i = 1;i <= n;i++)
        if(mx[i] != -1  &&  !vis[i])dp(i);
    for(int i = 1;i <= n;i++)
        if(mx[i] == inf)mx[i] = -2;
    for(int i = 1;i <= n;i++)
        printf("%d %d\n" , min(mn[i],314000000) , min(mx[i],314000000));
    return 0;
    cout << "LSY is handsome\n";
}